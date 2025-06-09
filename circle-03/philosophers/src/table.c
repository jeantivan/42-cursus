/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:22:31 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/28 17:18:12 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_table	*init_table(int ac, char **av)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (ft_puterror(ERR_CREATE_TABLE, NULL), NULL);
	table->finished = false;
	table->num_philos = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (ac == 6)
		table->num_meals = ft_atol(av[5]);
	else
		table->num_meals = -1;
	table->table_ready = false;
	pthread_mutex_init(&table->print_mtx, NULL);
	pthread_mutex_init(&table->table_mtx, NULL);
	// TODO: Inicializar print_mtx y meals_mtx;
	return (table);
}

t_table	*clean_table(t_table *table, char *reason)
{
	clean_forks(table->forks, table->num_philos);
	// TODO: Destroy mutexes
	pthread_mutex_destroy(&table->table_mtx);
	pthread_mutex_destroy(&table->print_mtx);
	// TODO: Clean table->philos
	// TODO: Destroy threads
	safe_free((void **)&table);
	if (reason)
		ft_puterror(reason, NULL);
	return (table);
}

t_table	*set_table(int ac, char **av)
{
	t_table	*table;

	table = init_table(ac, av);
	if (!table)
		return (NULL);
	if (!create_forks(table))
		return (clean_table(table, ERR_CREATE_FORKS));
	if (!create_philos(table))
		return (clean_table(table, ERR_CREATE_PHILOS));
	return (table);
}

void	set_table_ready(t_table *table)
{
	pthread_mutex_lock(&table->table_mtx);
	table->table_ready = true;
	pthread_mutex_unlock(&table->table_mtx);
}

bool	is_table_ready(t_table *table)
{
	bool	res;

	pthread_mutex_lock(&table->table_mtx);
	res = table->table_ready;
	pthread_mutex_unlock(&table->table_mtx);
	return (res);
}
