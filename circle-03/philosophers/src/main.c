/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:40:48 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/16 12:44:52 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
