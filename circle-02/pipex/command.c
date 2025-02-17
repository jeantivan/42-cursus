/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean <jean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:56 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/16 14:36:58 by jean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	check_access(char *path)
{
	return (access(path, F_OK) == 0);
}

char	*check_access_from_paths(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*path_tmp;

	cmd_path = ft_strjoin("/", cmd);
	i = 0;
	path_tmp = NULL;
	while (paths[i])
	{
		if (ft_strlen(paths[i]) > 0)
		{
			path_tmp = ft_strjoin(paths[i], cmd_path);
			if (!path_tmp)
				return (ft_safe_free((void **)&cmd_path));
			if (access(path_tmp, F_OK) == 0)
				break ;
			ft_safe_free((void **)&path_tmp);
			i++;
		}
	}
	ft_safe_free((void **)&cmd_path);
	return (path_tmp);
}

char	*get_sys_cmd_path(char *cmd_str, char **env)
{
	char	*env_path;
	char	**paths;
	char	*cmd;

	env_path = get_env_var(env, "PATH");
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path + 5, ':');
	if (!paths)
		return (NULL);
	cmd = check_access_from_paths(paths, cmd_str);
	ft_free_split(paths);
	return (cmd);
}

char	*find_cmd_abs_path(char *cmd_str, char **env)
{
	char	*cmd;
	char	*cmd_path;
	int		end;

	if (cmd_str[0] == '\0')
		return (NULL);
	end = 0;
	while (cmd_str[end])
	{
		if (cmd_str[end] == ' ')
			break ;
		end++;
	}
	cmd = ft_substr(cmd_str, 0, end);
	if (cmd[0] != '.' && cmd[0] != '/')
	{
		cmd_path = get_sys_cmd_path(cmd, env);
		ft_safe_free((void **)&cmd);
		return (cmd_path);
	}
	return (cmd);
}

t_cmd	*get_cmd(char *raw_cmd, char **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->raw_cmd = raw_cmd;
	cmd->path = find_cmd_abs_path(cmd->raw_cmd, env);
	if (ft_strchr(cmd->raw_cmd, '/') && \
	ft_strrchr(cmd->raw_cmd, '/')[0] != '\0')
		cmd->args = ft_split(ft_strrchr(cmd->raw_cmd, '/') + 1, ' ');
	else
		cmd->args = ft_split(cmd->raw_cmd, ' ');
	if (!cmd->args)
	{
		ft_safe_free((void **)&cmd->path);
		ft_safe_free((void **)&cmd);
		return (NULL);
	}
	return (cmd);
}
