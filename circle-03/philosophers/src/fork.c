/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:19:50 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/21 19:32:22 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean_forks(t_fork *forks, long qty)
{
	long	i;

	i = 0;
	while (i < qty)
	{
		pthread_mutex_destroy(&forks[i].fork);
		i++;
	}
	safe_free((void **)&forks);
}

bool	create_forks(t_table *table)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(table->num_philos * sizeof(t_fork));
	if (!forks)
		return (false);
	i = -1;
	while (++i < table->num_philos)
	{
		forks[i].id = i;
		if (pthread_mutex_init(&forks[i].fork, NULL) < 0)
			return (clean_forks(forks, i), false);
	}
	table->forks = forks;
	return (true);
}
