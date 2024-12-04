/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:19:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 17:50:10 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sx(t_stack *stack, char letter)
{
	if (letter != 'a' && letter != 'b')
		exit(EXIT_FAILURE);

	swap(stack);
	if (letter == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	return (1);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return (2);
}
