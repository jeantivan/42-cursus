/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:19:58 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 18:45:08 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	px(t_stack *stack_a, t_stack *stack_b, char letter)
{
	if (letter != 'a' && letter != 'b')
		exit(EXIT_FAILURE);
	if (letter == 'a')
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	else
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	return (1);
}
