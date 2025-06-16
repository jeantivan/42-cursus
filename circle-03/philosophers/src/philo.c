/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:43:56 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/16 12:45:07 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_philos(t_philo *philos, long qty)
{
	long	i;

	i = -1;
	while (++i < qty)
		pthread_mutex_destroy(&philos[i].mtx);
	safe_free((void **)&philos);
}

static void	assign_forks(t_philo *philo, t_table *table, long pos, long qty)
{
	philo->first_fork = &table->forks[(pos + 1) % qty];
	philo->second_fork = &table->forks[pos];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &table->forks[pos];
		philo->second_fork = &table->forks[(pos + 1) % qty];
	}
}

bool	create_philos(t_table *table)
{
	t_philo	*philos;
	long	i;
	long	qty;

	qty = table->num_philos;
	philos = (t_philo *)malloc(sizeof(t_philo) * qty);
	if (!philos)
		return (false);
	i = -1;
	while (++i < table->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].is_dead = false;
		philos[i].full = false;
		assign_forks(&philos[i], table, i, qty);
		philos[i].table = table;
		pthread_mutex_init(&philos[i].mtx, NULL);
	}
	table->philos = philos;
	return (true);
}

