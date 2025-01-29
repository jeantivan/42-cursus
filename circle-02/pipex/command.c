/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:56 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/29 14:28:06 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

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
	ft_safe_free((void **)&cmd_path);
	return (path_tmp);
}

char	*get_pwd_cmd_path(char *cmd_str, char **env)
{
	char	*pwd_path;
	char	**cmd_args;

	pwd_path = get_env_var(env, "PWD");
	if (!pwd_path)
		return (NULL);
	cmd_args = ft_split(cmd_str, ' ');
	if (!cmd_args)
		return (NULL);
	pwd_path = ft_strjoin(pwd_path + 4, cmd_args[0] + 1);
	//ft_printf("-- Brake -- %s\n", pwd_path);
	ft_free_split(cmd_args);
	if (!check_access(pwd_path))
		ft_safe_free((void **)&pwd_path);
	return (pwd_path);
}

char	*get_sys_cmd_path(char *cmd_str, char **env)
{
	char	*env_path;
	char	**paths;
	char	**cmd_args;
	char	*cmd;

	env_path = get_env_var(env, "PATH");
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path + 5, ':');
	if (!paths)
		return (NULL);
	cmd_args = ft_split(cmd_str, ' ');
	if (!cmd_args)
		return (NULL);
	cmd = check_access_from_paths(paths, cmd_args[0]);
	ft_free_split(paths);
	ft_free_split(cmd_args);
	return (cmd);
}

char	*find_cmd_abs_path(char *cmd_str, char **env)
{
	char	*cmd_path;

	//ft_printf("%s\n", cmd_str);
	if (is_relative_cmd(cmd_str))
	{
		//ft_printf("Is rel cmd\n");
		cmd_path = get_pwd_cmd_path(cmd_str, env);
	}
	else
	{
		//ft_printf("Is not rel cmd\n");
		cmd_path = get_sys_cmd_path(cmd_str, env);
	}
	return (cmd_path);
}
