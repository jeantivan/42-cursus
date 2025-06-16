/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:40:31 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/16 13:15:45 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*waiter_job(void *data)
{
	long	i;
	t_table	*table;

	table = (t_table *)data;
	my_usleep(100, table);
	while (!dinner_finished(table))
	{
		i = -1;
		while (++i < table->num_philos && !dinner_finished(table))
		{
			if (philo_died(&table->philos[i]))
			{
				write_state(DIE, &table->philos[i]);
				set_dinner_finished(table, true);
			}
		}
		my_usleep(100, table);
	}
	return (NULL);
}

void	*dinner_for_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!is_table_ready(philo->table))
		;
	pthread_mutex_lock(&philo->mtx);
	philo->last_meal_time = get_time(MILI);
	pthread_mutex_unlock(&philo->mtx);
	write_state(TAKE_FIRST_FORK, philo);
	while (!dinner_finished(philo->table))
		usleep(100);
	return (NULL);
}

void	*dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!is_table_ready(philo->table))
		;
	pthread_mutex_lock(&philo->mtx);
	philo->last_meal_time = get_time(MILI);
	pthread_mutex_unlock(&philo->mtx);
	if (philo->table->num_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			my_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
	while (!dinner_finished(philo->table))
	{
		if (is_full(philo))
			break ;
		(eating(philo), sleeping(philo), thinking(philo, false));
	}
	return (NULL);
}
