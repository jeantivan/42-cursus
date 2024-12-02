/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:35:13 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/02 21:57:23 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "sort.h"
#include "utils.h"
#include "movs.h"

int	sort_1(t_stack *stack_a, t_stack *stack_b)
{
	int		operations;
	//int temp;
	(void)stack_b;
	operations = 0;

	set_indexes(stack_a);

	show_stack(stack_a);
	/* while (stack_a->size != 0)
	{
		temp = peek(stack_a->head);
		if (stack_a->size >= 2 && stack_b->size > 0)
			operations+= ra(stack_a);
		while (stack_b->size && peek(stack_b->head) > temp)
			operations += pa(stack_a, stack_b);
		operations += rra(stack_a) + pb(stack_a, stack_b);
	}
	while (stack_b->size != 0)
		operations += pa(stack_a, stack_b); */
	return (operations);
}

int	sort_3(t_stack *stack_a, t_stack *stack_b)
{
	int	op = 0;
	int	count;
	int	temp;
	int	stack_b_min;
	int	stack_b_max;

	/* if(peek(stack_a->head) > peek(stack_a->head->next))
		op += sa(stack_a);
	op += pb(stack_a, stack_b) + pb(stack_a, stack_b);
	show_stack(stack_a);
	show_stack(stack_b); */
	while (stack_a->size)
	{
	if (stack_b->size == 0)
		{
			op += pb(stack_a, stack_b);
			stack_b_max = peek(stack_b->head);
			stack_b_min = peek(stack_b->head);
		}
		else
		{
			count = 0;
			temp = peek(stack_a->head);
			if (!(temp > stack_b_max) && !(temp < stack_b_min))
			{
				while(temp < peek(stack_b->head))
					count += rb(stack_b);
				op += pb(stack_a, stack_b) + count + count;
				while(count)
					count -= rrb(stack_b);
			} else if (temp < stack_b_min)
			{
				op += pb(stack_a, stack_b) + rb(stack_b);
				stack_b_min = temp;
			} else
			{
				op += pb(stack_a, stack_b);
				stack_b_max = temp;
			}
		}
	}
	while (stack_b->size)
		op += pa(stack_a, stack_b);
	return (op);
}
