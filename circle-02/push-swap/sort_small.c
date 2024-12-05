/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:08:29 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/05 19:12:55 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_and_rotate(t_stack *stack, char letter)
{
	int		op;
	int		pos;
	int		i;
	int		curr_min;
	t_list	*curr_node;

	op = 0;
	pos = 0;
	i = 0;
	curr_node = stack->head;
	curr_min = peek(curr_node);
	while (i < stack->size)
	{
		if (curr_min > peek(curr_node))
		{
			pos = i;
			curr_min = peek(curr_node);
		}
		i++;
		curr_node = curr_node->next;
	}
	op += best_rotate(pos, stack, letter);
	return (op);
}

int	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	op;

	op = 0;
	while (stack_a->size != 3)
		op += find_min_and_rotate(stack_a, 'a') + px(stack_a, stack_b, 'b', true);
	op += sort_stack_3(stack_a, 'a');
	while (stack_b->size)
		op += px(stack_a, stack_b, 'a', true);
	return (op);
}
