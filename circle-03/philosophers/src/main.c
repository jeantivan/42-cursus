/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:40:48 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/09 16:03:07 by jtivan-r         ###   ########.fr       */
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

void	*waiter_job(void *data)
{
	long	i;
	t_table	*table;

	table = (t_table *)data;
	my_usleep(100, table);
	while(!dinner_finished(table))
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
		eating(philo);
		sleeping(philo);
		thinking(philo, false);
	}
	return (NULL);
}

void	start_dinner(t_table *table)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = table->philos;

	if (table->num_meals == 0)
		return ;
	else if (table->num_philos == 1)
		pthread_create(&philos[0].thread, NULL, dinner_for_one, &philos[0]);
	else
	{
		while (++i < table->num_philos)
			pthread_create(&philos[i].thread, NULL, dinner, &philos[i]);
	}
	pthread_create(&table->waiter, NULL, waiter_job, table);
	table->start_time = get_time(MILI);
	set_table_ready(table);
	i = -1;
	while (++i < table->num_philos)
		pthread_join(table->philos[i].thread, NULL);
	set_dinner_finished(table, true);
	pthread_join(table->waiter, NULL);
}

int	main(int ac, char **av)
{
	t_table		*table;

	if (!valid_args(ac, av))
		return (EXIT_FAILURE);
	table = set_table(ac, av);
	if (!table)
		return (EXIT_FAILURE);
	start_dinner(table);
	clean_table(table, NULL);
	return (0);
}
