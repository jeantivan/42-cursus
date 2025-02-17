/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:57:38 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/17 12:44:52 by jtivan-r         ###   ########.fr       */
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

void	ft_error(char *err_msg, char *err_desc, int exit_code)
{
	ft_putstr_fd((char *)err_msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (err_desc)
		ft_putstr_fd(err_desc, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(exit_code);
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

void	execute(t_cmd *cmd, char **env)
{
	if (!cmd->path)
		ft_error(cmd->raw_cmd, "command not found.", 127);
	if (access(cmd->path, F_OK) != 0 || cmd->path[0] == '\0')
		ft_error(cmd->raw_cmd, "command not found.", 127);
	execve(cmd->path, cmd->args, env);
	exit(1);
}
