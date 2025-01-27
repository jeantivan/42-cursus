/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/27 16:17:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*check_access_from_paths(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*path_tmp;

	cmd_path = ft_strjoin("/", cmd);
	i = 0;
	while (paths[i])
	{
		path_tmp = ft_strjoin(paths[i], cmd_path);
		if (access(path_tmp, F_OK) == 0)
			break ;
		ft_safe_free((void **)&path_tmp);
		i++;
	}
	// TODO: Investigar si el proyecto necesita gestionar "programas en rutas especificas"
	ft_safe_free((void **)&cmd_path);
	return (path_tmp);
}

char	*find_cmd_path(char **env, char *cmd_str)
{
	char	**paths;
	char	**cmd_args;
	char	*path_to_cmd;

	paths = ft_split(find_path_env(env), ':');
	cmd_args = ft_split(cmd_str, ' ');
	path_to_cmd = check_access_from_paths(paths, cmd_args[0]);
	if (!path_to_cmd)
		ft_printf("Error: Could not find path for '%s'\n", cmd_args[0]);
	ft_free_split(paths);
	ft_free_split(cmd_args);
	return (path_to_cmd);
}

int	main(int ac, char **av, char **env)
{
	char	*path;

	if (ac == 1)
		return (EXIT_FAILURE);
	path = find_cmd_path(env, av[2]);
	if (!path)
		exit(EXIT_FAILURE);
	ft_printf("%s\n", path);
	ft_safe_free((void **)&path);
	return (0);
}
