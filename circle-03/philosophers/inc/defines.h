/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:21:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/21 19:21:56 by jtivan-r         ###   ########.fr       */
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

# define ERR_CREATE_TABLE "Could not allocate memory for 'table'"
# define ERR_CREATE_FORKS "Could not allocate memory or init mutexes for 'table->forks'"

typedef pthread_mutex_t	t_mxt;

typedef struct s_fork
{
	int		id;
	t_mxt	fork;
}	t_fork;

typedef struct s_table
{
	long	num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_meals;
	long	start_time;
	bool	end_dinner;
	t_fork	*forks;
	t_philo	*philos;
	t_mxt	*print_mutex;
	t_mxt	*meal_mutex;
}	t_table;

typedef struct s_philo
{
	int		id;
	int		eat_count;
	long	last_meal_time;
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_table	*table;
}	t_philo;

#endif /* defines.h */
