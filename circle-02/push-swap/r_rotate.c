/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:21:31 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 18:26:52 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	rrx(t_stack *stack, char letter)
{
	if (letter != 'a' && letter != 'b')
		exit(EXIT_FAILURE);
	reverse_r(stack);
	if (letter == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_r(stack_a);
	reverse_r(stack_b);
	ft_printf("rrr\n");
	return (2);
}
