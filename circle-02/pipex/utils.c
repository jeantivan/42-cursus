/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean <jean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:57:38 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/20 15:25:57 by jean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env_var(char **env, const char *var)
{
	int		i;
	size_t	var_len;

	var_len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, var_len) == 0)
			break ;
		i++;
	}
	return (env[i]);
}

void	ft_error(char *err_msg, char *err_desc)
{
	int		total_len;
	char	*msg;

	if (!err_msg || !err_desc)
		return ;
	total_len = ft_strlen(err_msg) + ft_strlen(err_desc) + 4;
	msg = (char *)malloc(sizeof(char) * total_len);
	if (!msg)
		return ;
	msg[0] = '\0';
	ft_strlcat(msg, err_msg, total_len);
	ft_strlcat(msg, ": ", total_len);
	ft_strlcat(msg, err_desc, total_len);
	ft_strlcat(msg, "\n", total_len);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_safe_free((void **)&msg);
}

t_pipex	*create_pipex(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		i;
	int		j;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->infile = av[1];
	pipex->outfile = av[ac - 1];
	pipex->n_cmds = ac - 3;
	pipex->cmds = (t_cmd **)malloc(sizeof(t_cmd *) * (ac - 3 + 1));
	if (!pipex->cmds)
		return (ft_safe_free((void **)&pipex));
	i = 2;
	j = 0;
	while (i < ac - 1)
	{
		pipex->cmds[j] = get_cmd(av[i], env);
		i++;
		j++;
	}
	pipex->cmds[j] = NULL;
	return (pipex);
}

void	clean_pipex(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->cmds)
	{
		while (pipex->cmds[i])
		{
			ft_safe_free((void **)&pipex->cmds[i]->path);
			ft_safe_free((void **)&pipex->cmds[i]->raw_cmd);
			ft_free_split(pipex->cmds[i]->args);
			ft_safe_free((void **)&pipex->cmds[i]);
			i++;
		}
	}
	ft_safe_free((void **)&pipex->cmds);
	ft_safe_free((void **)&pipex);
}

int	execute(t_cmd *cmd, char **env)
{
	if (!cmd->path)
		return (-1);
	if (access(cmd->path, F_OK) != 0 || cmd->path[0] == '\0')
		return (-1);
	execve(cmd->path, cmd->args, env);
	return (-1);
}
