/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:21:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/17 22:23:45 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>

//Colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BGRED "\033[41;37m"
# define BGCYAN "\033[46;37m"
# define BGGREEN "\033[42;37m"
# define BGYELLOW "\033[43;37m"
# define BGMAGENTA "\033[45;37m"
# define BGBLUE "\033[44;37m"
# define RST "\033[0m"

# define MAX_PHILOS 200

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
