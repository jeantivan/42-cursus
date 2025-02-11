/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/11 11:27:07 by jtivan-r         ###   ########.fr       */
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

/* Command */
char	*find_cmd_abs_path(char *cmd_str, char **env);

/* Utils */
bool	is_relative_cmd(char *cmd_path);
char	*get_env_var(char **env, const char *var);
void	*ft_safe_free(void **ptr);
void	*ft_free_split(char **splited);
int		ft_error(const char *err_msg);
bool	valid_args(int ac, char **av);

#endif /* pipex.h */
