/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:19:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/05 19:09:40 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sx(t_stack *stack, char letter, bool print)
{
	if (letter != 'a' && letter != 'b')
		exit(EXIT_FAILURE);
	swap(stack);
	if (print)
	{
		if (letter == 'a')
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
	return (1);
}

int	ss(t_stack *stack_a, t_stack *stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
	return (2);
}
