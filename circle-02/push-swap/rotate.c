/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:21:07 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/03 23:13:03 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return (2);
}
