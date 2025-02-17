/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/17 12:31:28 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	show_pipex(t_pipex *pipex)
{
	int	i;
	int	j;

	ft_printf("infile: %s outfile: %s\n", pipex->infile, pipex->outfile);
	ft_printf("n_cmds: %d\n", pipex->n_cmds);
	i = 0;
	while (pipex->cmds[i])
	{
		ft_printf("cmd #%d: %s\n", i, pipex->cmds[i]->raw_cmd);
		ft_printf(" path: %s\n", pipex->cmds[i]->path);
		j = 0;
		while (pipex->cmds[i]->args[j])
		{
			ft_printf(" arg #%d: %s\n", j, pipex->cmds[i]->args[j]);
			j++;
		}
		ft_printf(" arg #%d: %s\n", j, pipex->cmds[i]->args[j]);
		i++;
	}
}

void	first_child(t_pipex *pipex, char **env, int pipe_fd[2])
{
	int	in_fd;

	close(pipe_fd[0]);
	in_fd = open(pipex->infile, O_RDONLY);
	if (in_fd < 0)
		ft_error(pipex->infile, strerror(errno), 1);
	if (dup2(in_fd, STDIN_FILENO) < 0)
	{
		close(in_fd);
		exit(1);
	}
	close(in_fd);
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
	{
		close(pipe_fd[1]);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	execute(pipex->cmds[0], env);
	clean_pipex(pipex);
	exit(127);
}

void	last_child(t_pipex *pipex, char **env, int pipe_fd[2])
{
	int	out_fd;

	close(pipe_fd[1]);
	out_fd = open(pipex->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (out_fd < 0)
		ft_error(pipex->outfile, strerror(errno), 1);
	if (dup2(out_fd, STDOUT_FILENO) < 0)
	{
		close(out_fd);
		exit(1);
	}
	close(out_fd);
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
	{
		close(pipe_fd[0]);
		exit(EXIT_FAILURE);
	}
	close(pipe_fd[0]);
	execute(pipex->cmds[pipex->n_cmds - 1], env);
	clean_pipex(pipex);
	exit(127);
}

int	wait_childs(int pid1, int pid2, t_pipex *pipex)
{
	int	status;

	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	clean_pipex(pipex);
	return (WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		pid1;
	int		pid2;
	int		pipe_fd[2];

	if (ac != 5)
		return (EXIT_FAILURE);
	pipex = create_pipex(ac, av, env);
	if (!pipex)
		return (EXIT_FAILURE);
	if (pipe(pipe_fd) < 0)
		(clean_pipex(pipex), exit(EXIT_FAILURE));
	pid1 = fork();
	if (pid1 < 0)
		(clean_pipex(pipex), exit(EXIT_FAILURE));
	if (pid1 == 0)
		first_child(pipex, env, pipe_fd);
	close(pipe_fd[1]);
	pid2 = fork();
	if (pid2 < 0)
		(clean_pipex(pipex), exit(EXIT_FAILURE));
	if (pid2 == 0)
		last_child(pipex, env, pipe_fd);
	close(pipe_fd[0]);
	return (wait_childs(pid1, pid2, pipex));
}
