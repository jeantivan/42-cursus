/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:15:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/09 15:57:00 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	dinner_finished(t_table *table)
{
	bool	ret;

	pthread_mutex_lock(&table->table_mtx);
	ret = table->finished;
	pthread_mutex_unlock(&table->table_mtx);
	return (ret);
}

void	set_dinner_finished(t_table *table, bool val)
{
	pthread_mutex_lock(&table->table_mtx);
	table->finished = val;
	pthread_mutex_unlock(&table->table_mtx);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_state(TAKE_FIRST_FORK, philo);
	pthread_mutex_lock(&philo->second_fork->fork);
	write_state(TAKE_SECOND_FORK, philo);
	pthread_mutex_lock(&philo->mtx);
	philo->last_meal_time = get_time(MILI);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mtx);
	write_state(EAT, philo);
	my_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->num_meals > 0 \
		&& philo->eat_count == philo->table->num_meals)
		set_full(philo, true);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}

void 	sleeping(t_philo *philo)
{
	write_state(SLEEP, philo);
	my_usleep(philo->table->time_to_sleep, philo->table);
}

void	thinking(t_philo *philo, bool pre_dinner)
{
	long	t_to_sleep;
	long	t_to_eat;
	long	t_to_think;

	if (!pre_dinner)
		write_state(THINK, philo);
	if (philo->table->num_philos % 2 == 0)
		return ;
	t_to_eat = philo->table->time_to_eat;
	t_to_sleep = philo->table->time_to_sleep;
	t_to_think = t_to_eat * 2 - t_to_sleep;
	if (t_to_think < 0)
		t_to_think = 0;
	my_usleep(t_to_think * 0.42, philo->table);
}
