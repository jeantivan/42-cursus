/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:40:48 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/17 22:51:33 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table		table;
	t_philo		*philos;
	int			i;

	if (!valid_args(ac, av))
		return (EXIT_FAILURE);
	(void)table;
	(void)philos;
	(void)i;
	return (0);
}
