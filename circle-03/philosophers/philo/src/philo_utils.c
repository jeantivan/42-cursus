/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:44:27 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/16 12:45:57 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_died(t_philo *philo)
{
	long	time_passed;
	long	last_meal_time;
	long	time_to_die;

	if (is_full(philo))
		return (false);
	pthread_mutex_lock(&philo->table->table_mtx);
	time_to_die = philo->table->time_to_die / 1e3;
	pthread_mutex_unlock(&philo->table->table_mtx);
	pthread_mutex_lock(&philo->mtx);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->mtx);
	time_passed = get_time(MILI) - last_meal_time;
	if (time_passed > time_to_die)
		return (true);
	return (false);
}

bool	is_full(t_philo *philo)
{
	bool	ret;

	pthread_mutex_lock(&philo->mtx);
	ret = philo->full;
	pthread_mutex_unlock(&philo->mtx);
	return (ret);
}

void	set_full(t_philo *philo, bool val)
{
	pthread_mutex_lock(&philo->mtx);
	philo->full = val;
	pthread_mutex_unlock(&philo->mtx);
}
