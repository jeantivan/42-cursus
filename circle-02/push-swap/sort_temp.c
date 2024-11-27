/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:35:13 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/27 18:37:39 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "sort.h"
#include "utils.h"
#include "movs.h"

int	sort_1(t_stack *stack_a, t_stack *stack_b)
{
	int		operations;
	int temp;

	operations = 0;
	while (stack_a->size != 0)
	{
		temp = peek(stack_a->head);
		if (stack_a->size >= 2)
			operations+= ra(stack_a);
		while (stack_b->size && peek(stack_b->head) > temp)
			operations += pa(stack_a, stack_b);
		operations += rra(stack_a) + pb(stack_a, stack_b);
	}
	while (stack_b->size != 0)
		operations += pa(stack_a, stack_b);
	return (operations);
}
