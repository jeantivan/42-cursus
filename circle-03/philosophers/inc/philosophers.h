/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:15:19 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/09 16:01:26 by jtivan-r         ###   ########.fr       */
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
void		*safe_free(void **ptr);
long		get_time(t_time_scale scale);
void		my_usleep(long usec, t_table *table);

/* Fork */
bool		create_forks(t_table *table);
void		clean_forks(t_fork *forks, long qty);

/* Table */
t_table		*set_table(int ac, char **av);
t_table		*clean_table(t_table *table, char *reason);
void		set_table_ready(t_table *table);
bool		is_table_ready(t_table *table);

/* Error */
int			ft_puterror(char *str, char *info);

/* Philo */
bool		create_philos(t_table *table);
void		clean_philos(t_philo *philos, long qty);
bool		is_full(t_philo *philo);
void		set_full(t_philo *philo, bool val);

/* Syncro */
bool		dinner_finished(t_table *table);
void		set_dinner_finished(t_table *table, bool val);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo, bool pre_dinner);

/* Write */
void		write_state(t_action action, t_philo *philo);

#endif /* philosophers.h */
