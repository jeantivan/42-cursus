/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:15:19 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/17 21:09:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <aio.h>
# include <string.h>

# include "defines.h"

/* Utils */
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *nptr);
long int	ft_atol(const char *nptr);
bool		valid_args(int ac, char **av);

/* Error */
int			ft_puterror(char *str, char *info);

#endif /* philosophers.h */
