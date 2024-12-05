/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:09:35 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/05 19:11:00 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_and_rotate(t_stack *stack, char letter)
{
	int		op;
	int		pos;
	t_list	*curr;

	curr = stack->head;
	pos = 0;
	op = 0;
	while (curr)
	{
		if (curr->index == (stack->size - 1))
			break ;
		pos++;
		curr = curr->next;
	}
	op += best_rotate(pos, stack, letter);
	return (op);
}

int	k_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		op;
	int		k;
	t_list	*top;

	op = 0;
	k = ft_sqrt(stack_a->size);
	while (stack_a->size)
	{
		top = stack_a->head;
		if (top->index <= stack_b->size)
			op += px(stack_a, stack_b, 'b', true);
		else if (top->index <= stack_b->size + k)
			op += px(stack_a, stack_b, 'b', true) + rx(stack_b, 'b', true);
		else
			op += rx(stack_a, 'a', true);
	}
	while (stack_b->size)
		op += find_max_and_rotate(stack_b, 'b') + px(stack_a, stack_b, 'a',
				true);
	return (op);
}
