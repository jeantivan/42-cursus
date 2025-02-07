/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/07 12:33:40 by jtivan-r         ###   ########.fr       */
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

int	main(int ac, char **av, char **env)
{
	t_cmds	*cmds;
	// char	**cmd1_args;
	// char	**cmd2_args;

	if (ac == 1 || ac != 5)
		return (EXIT_FAILURE);
	if (!file_access(ac, av))
		return (EXIT_FAILURE);
	cmds = find_cmds(av, env);
	if (!cmds)
		return (EXIT_FAILURE);
	ft_printf("%s\n", cmds->cmd_1);
	ft_printf("%s\n", cmds->cmd_2);
	// cmd1_args = ft_split(av[1], ' ');
	// cmd2_args = ft_split(av[2], ' ');
	// execve(cmds->cmd_1, cmd1_args, env);
	// execve(cmds->cmd_2, cmd2_args, env);
	free_cmds(cmds);
	return (0);
}
