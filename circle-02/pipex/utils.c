/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:57:38 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/11 11:24:31 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	is_relative_cmd(char *cmd_path)
{
	return (ft_strncmp(cmd_path, "./", 2) == 0 && cmd_path[2] != '\0');
}

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

int	ft_error(const char *err_msg)
{
	perror(err_msg);
	return (EXIT_FAILURE);
}

bool	valid_args(int ac, char **av)
{
	while (--ac)
		if (av[ac][0] == '\0')
			return (false);
	return (true);
}
