/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:40:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/09 16:04:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_state(t_action action, t_philo *philo)
{
	long	time_passed;

	if (is_full(philo))
		return ;
	time_passed = get_time(MILI) - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print_mtx);
	if (action == TAKE_FIRST_FORK && !dinner_finished(philo->table))
		printf(YELLOW"%-6ld %d has taken his first fork [ %d 🍴] \n"RST, time_passed, philo->id, philo->first_fork->id);
	else if (action == TAKE_SECOND_FORK && !dinner_finished(philo->table))
		printf(BLUE"%-6ld %d has taken his second fork [ %d 🍴] \n"RST, time_passed, philo->id, philo->second_fork->id);
	else if (action == EAT && !dinner_finished(philo->table))
		printf(GREEN"%-6ld %d is eating 🍽️\n"RST, time_passed, philo->id);
	else if (action == SLEEP && !dinner_finished(philo->table))
		printf(CYAN"%-6ld %d is sleeping 😴\n"RST, time_passed, philo->id);
	else if (action == THINK && !dinner_finished(philo->table))
		printf(MAGENTA"%-6ld %d is thinking 🤔\n"RST, time_passed, philo->id);
	else if (action == DIE && !dinner_finished(philo->table))
		printf(RED"%-6ld %d has died 😵​\n"RST, time_passed, philo->id);
	pthread_mutex_unlock(&philo->table->print_mtx);
}
