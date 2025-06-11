/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:33:22 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/11 16:58:48 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(t_time_scale scale)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (scale == MILI)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (scale == MICRO)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	return (-1);
}

void	my_usleep(long usec, t_table *table)
{
	long	start;

	start = get_time(MICRO);
	while (get_time(MICRO) - start < usec)
	{
		if (dinner_finished(table))
			break ;
		usleep(100);
	}
}
