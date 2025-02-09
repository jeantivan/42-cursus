/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/07 14:40:16 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

typedef	struct	s_cmds
{
	char	*cmd_1;
	char	*cmd_2;
} t_cmds;

void	free_cmds(t_cmds *cmds)
{
	ft_safe_free((void **)&cmds->cmd_1);
	ft_safe_free((void **)&cmds->cmd_2);
	ft_safe_free((void **)&cmds);
}

t_cmds	*find_cmds(char **av, char **env)
{
	t_cmds	*cmds;

	cmds = (t_cmds *)malloc(sizeof(t_cmds));
	if (!cmds)
		return (NULL);
	cmds->cmd_1 = find_cmd_abs_path(av[2], env);
	if (!cmds->cmd_1)
	{
		ft_printf("%s: Command could not be found.\n", av[2]);
		return (ft_safe_free((void **)&cmds));
	}
	cmds->cmd_2 = find_cmd_abs_path(av[3], env);
	if (!cmds->cmd_2)
	{
		ft_printf("%s: Command could not be found.\n", av[2]);
		ft_safe_free((void **)&cmds->cmd_1);
		return (ft_safe_free((void **)&cmds));
	}
	return (cmds);
}

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

bool	file_access(int ac, char **av)
{
	bool	con;

	con = true;
	if (access(av[1], F_OK) != 0 || access(av[1], R_OK) != 0)
	{
		ft_printf("%s: Permiso denegado.\n", av[1]);
		con = false;
	}
	if (access(av[ac - 1], F_OK) == 0 && access(av[ac - 1], W_OK) != 0)
	{
		ft_printf("%s: Permiso denegado.\n", av[ac - 1]);
		con = false;
	}
	return (con);
}

int	redirect_std(char *infile, char *outfile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		perror(infile);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("Redirect infile to STDIN");
		close(fd);
		return (-1);
	}
	close(fd);
	fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (fd < 0)
	{
		perror(outfile);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("Redirect outfile to STDOUT");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	pid;

	if (ac == 1 || ac != 5)
		return (EXIT_FAILURE);
	if (!file_access(ac, av))
		return (EXIT_FAILURE);
	if (redirect_std(av[1], av[ac - 1]) < 0)
		return (EXIT_FAILURE);
	if (pipe(fd) < 0)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			return (EXIT_FAILURE);
		close(fd[1]);
		execute(av[2], env);
		perror("execute in child");
		return (EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) < 0)
			return (EXIT_FAILURE);
		close(fd[0]);
		execute(av[3], env);
		perror("execute in parent");
		return (EXIT_SUCCESS);
	}
	return (0);
}
