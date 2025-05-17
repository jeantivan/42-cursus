/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:23:50 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/17 22:56:34 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	valid_arg(char *arg, int index)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg[i] != ' ' || arg[i] != '\t')
			break ;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (ft_puterror("Bad argument", "Use only digits"), false);
		i++;
	}
	if (ft_atoi(arg) != ft_atol(arg))
		return (ft_puterror("Number too big!", "number <= [INT_MAX]"), false);
	if (index == 1 && ft_atoi(arg) > 200)
		return (ft_puterror("Too many philos 🥵", "Max number is 200"), false);
	return (true);
}

bool	valid_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
	{
		ft_puterror("Bad number of arguments.", \
			"Use: \
./philo <nbr_of_philos>  \
<time_to_die> <time_to_eat> <time_to_sleep> \
[nbr_of_times_each_philo_must_eat]");
		return (false);
	}
	i = 0;
	while (++i < ac)
	{
		if (!valid_arg(av[i], i))
			return (false);
	}
	return (true);
}
