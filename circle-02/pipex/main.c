/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/11 17:04:46 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **env)
{
	char	*cmd_path;
	char	**cmd_args;

	if (cmd[0] == '\0' && access(cmd, F_OK) != 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		exit(EXIT_FAILURE);
	cmd_path = find_cmd_abs_path(cmd_args[0], env);
	if (!cmd_path)
	{
		perror("command not found");
		ft_free_split(cmd_args);
		return ;
	}
	execve(cmd_path, cmd_args, env);
	ft_free_split(cmd_args);
	exit(EXIT_FAILURE);
}

bool	redirect_file(char *file, int dest_fd, int flags, int opts)
{
	int	fd;

	fd = open(file, flags, opts);
	if (fd < 0)
	{
		perror(file);
		return (false);
	}
	if (dup2(fd, dest_fd) < 0)
	{
		close(fd);
		perror("While redirecting file");
		return (false);
	}
	close(fd);
	return (true);
}

int	first_child(char **av, char **env, int pipe_fd[2])
{
	close(pipe_fd[0]);
	if (!redirect_file(av[1], STDIN_FILENO, O_RDONLY, 0644))
	{
		close(pipe_fd[1]);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
	{
		close(pipe_fd[1]);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	execute(av[2], env);
	return (1);
}

int	last_child(int ac, char **av, char **env, int pipe_fd[2])
{
	if (!redirect_file(av[ac - 1], STDOUT_FILENO, \
	O_CREAT | O_TRUNC | O_WRONLY, 0644))
	{
		close(pipe_fd[1]);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
	{
		close(pipe_fd[0]);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	execute(av[ac - 2], env);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;

	if (ac != 5)
		return (EXIT_FAILURE);
	if (pipe(pipe_fd) < 0)
		return (ft_error("Error: while creating the pipe"));
	pid1 = fork();
	if (pid1 < 0)
		exit(EXIT_FAILURE);
	if (pid1 == 0)
		return (first_child(av, env, pipe_fd));
	close(pipe_fd[1]);
	pid2 = fork();
	if (pid2 < 0)
		exit(EXIT_FAILURE);
	if (pid2 == 0)
		return (last_child(ac, av, env, pipe_fd));
	close(pipe_fd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
