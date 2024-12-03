/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 00:09:35 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 00:10:17 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_and_rotate(t_stack *stack)
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
	if (pos <= stack->size / 2)
		while (pos--)
			op += rb(stack);
	else
	{
		pos = stack->size - pos;
		while (pos--)
			op += rrb(stack);
	}
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
			op += pb(stack_a, stack_b);
		else if (top->index <= stack_b->size + k)
			op += pb(stack_a, stack_b) + rb(stack_b);
		else
			op += ra(stack_a);
	}
	while (stack_b->size)
		op += find_max_and_rotate(stack_b) + pa(stack_a, stack_b);
	return (op);
}
