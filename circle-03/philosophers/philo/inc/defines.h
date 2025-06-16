/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:21:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/11 16:59:31 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>

//Colors
# define R "\033[31m"
# define G "\033[32m"
# define Y "\033[33m"
# define B "\033[34m"
# define M "\033[35m"
# define C "\033[36m"
# define W "\033[37m"
# define BGR "\033[41;37m"
# define BGC "\033[46;37m"
# define BGG "\033[42;37m"
# define BGY "\033[43;37m"
# define BGM "\033[45;37m"
# define BGB "\033[44;37m"
# define RST "\033[0m"

# define MAX_PHILOS 200

/* Error messages */
# define ERR_BAD_ARGS "Bad number of arguments."
# define ERR_CREATE_TABLE "Could not allocate memory for 'table'"
# define ERR_CREATE_FORKS "Could not allocate memory or init \
mutexes for 'table->forks'"
# define ERR_CREATE_PHILOS "Could not allocate memory for 'table->philos'"

/* Info messages */
# define INFO_BAD_ARGS "Use: ./philo <nbr_of_philos>  \
<time_to_die> <time_to_eat> <time_to_sleep> \
[nbr_of_times_each_philo_must_eat]"

typedef pthread_mutex_t	t_mtx;
typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

struct s_fork
{
	int		id;
	t_mtx	fork;
};

struct s_table
{
	long		num_philos;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		num_meals;
	long		start_time;
	bool		finished;
	t_fork		*forks;
	t_philo		*philos;
	bool		table_ready;
	t_mtx		print_mtx;
	t_mtx		table_mtx;
	pthread_t	waiter;
};

struct s_philo
{
	int			id;
	pthread_t	thread;
	int			eat_count;
	long		last_meal_time;
	bool		is_dead;
	bool		full;
	t_fork		*first_fork;
	t_fork		*second_fork;
	t_mtx		mtx;
	t_table		*table;
};

/* Time scale */
typedef enum e_time_scale
{
	MILI,
	MICRO
}	t_time_scale;

/* Philo actions */
typedef enum e_action
{
	EAT,
	SLEEP,
	THINK,
	DIE,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK
}	t_action;

#endif /* defines.h */
