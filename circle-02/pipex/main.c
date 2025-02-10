/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/10 17:33:26 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **env)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_path = find_cmd_abs_path(cmd, env);
	if (!cmd_path)
		return ;
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		return ;
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

bool	valid_args(int ac, char **av)
{
	while (--ac)
		if (av[ac][0] == '\0')
			return (false);
	return (true);
}

int	main(int ac, char **av, char **env)
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;

	if (ac != 5 || !valid_args(ac, av))
		return (EXIT_FAILURE);
	if (pipe(pipe_fd) < 0)
		return (ft_error("Error: while creating the pipe"));
	pid1 = fork();
	if (pid1 < 0)
		return (ft_error("Error: while forking proccess"));
	if (pid1 == 0)
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
	}
	pid2 = fork();
	if (pid2 < 0)
		exit(EXIT_FAILURE);
	if (pid2 == 0)
	{
		close(pipe_fd[1]);
		if (!redirect_file(av[ac - 1], STDOUT_FILENO, \
		O_CREAT | O_TRUNC | O_WRONLY, 0644))
		{
			close(pipe_fd[1]);
			exit(EXIT_FAILURE);
		}
		if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
		{
			close(pipe_fd[0]);
			exit(EXIT_FAILURE);
		}
		close(pipe_fd[0]);
		execute(av[3], env);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
