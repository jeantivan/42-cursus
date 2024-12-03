/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:35:13 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/03 16:14:38 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "movs.h"
#include "sort.h"
#include "utils.h"

int	sort_1(t_stack *stack_a, t_stack *stack_b)
{
	int		op;
	int		k;
	t_list	*top;

	op = 0;
	k = ft_sqtr(stack_a->size);
	while (stack_a->size)
	{
		top = stack_a->head;
		if (top->index <= stack_b->size)
			op += pb(stack_a, stack_b);
		else if (top->index <= stack_b->size + k)
			op += pb(stack_a, stack_b) + rb(stack_b);
		else
			op += ra(stack_a);
	}
	return (op);
}

int	sort_3(t_stack *stack_a, t_stack *stack_b)
{
	int	op;
	int	count;
	int	temp;
	int	stack_b_min;
	int	stack_b_max;

	op = 0;
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
				while (temp < peek(stack_b->head))
					count += rb(stack_b);
				op += pb(stack_a, stack_b) + count + count;
				while (count)
					count -= rrb(stack_b);
			}
			else if (temp < stack_b_min)
			{
				op += pb(stack_a, stack_b) + rb(stack_b);
				stack_b_min = temp;
			}
			else
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
