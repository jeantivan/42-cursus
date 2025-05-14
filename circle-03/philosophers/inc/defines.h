/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:21:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/14 11:39:51 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>

//Colors
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define RST "\033[1;0m"

typedef pthread_mutex_t	t_mxt;

typedef struct s_table
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_meals;
	long	start_time;
	bool	is_dead;
	t_mxt	*print_mutex;
	t_mxt	*meal_mutex;
}	t_table;

typedef struct s_philo
{
	int		id;
	int		eat_count;
	long	last_meal_time;
	t_mxt	*left_fork;
	t_mxt	*right_fork;
	t_mxt	*print_mutex;
	t_mxt	*meal_mutex;
	t_table	*table;
}	t_philo;

#endif /* defines.h */
