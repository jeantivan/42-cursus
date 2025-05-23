/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean <jean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/20 15:00:18 by jean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>

/* Command */
typedef struct s_cmd
{
	char	*raw_cmd;
	char	*path;
	char	**args;
}	t_cmd;
typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	size_t	n_cmds;
	t_cmd	**cmds;
}	t_pipex;

char	*find_cmd_abs_path(char *cmd_str, char **env);
t_cmd	*get_cmd(char *raw_cmd, char **env);

/* Utils */
void	ft_error(char *err_msg, char *err_desc);
char	*get_env_var(char **env, const char *var);
t_pipex	*create_pipex(int ac, char **av, char **env);
void	clean_pipex(t_pipex *pipex);
int		execute(t_cmd *cmd, char **env);

#endif /* pipex.h */
