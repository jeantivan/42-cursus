/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:46:27 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 01:02:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_stack_2(t_stack *stack)
{
	if (peek(stack->head) > peek(stack->head->next))
		return (sa(stack));
	return (0);
}

static int	sort_stack_3(t_stack *stack)
{
	t_list	*node;
	int		op;
	int		n1;
	int		n2;
	int		n3;

	op = 0;
	if (!stack->head || stack->size < 3)
		return (-1);
	node = stack->head;
	n1 = peek(node);
	n2 = peek(node->next);
	n3 = peek(node->next->next);
	if ((n1 > n2) && (n2 < n3) && (n1 > n3))
		op += ra(stack);
	else if ((n1 > n2) && (n1 < n3) && (n2 < n3))
		op += sa(stack);
	else if ((n1 > n2) && (n1 > n3) && (n2 > n3))
		op += ra(stack) + sa(stack);
	else if ((n1 < n2) && (n1 < n3) && (n2 > n3))
		op += rra(stack) + sa(stack);
	return (op);
}

static int	sort_stack_4(t_stack *stack_a, t_stack *stack_b)
{
	int	op;
	int	index;

	op = pb(stack_a, stack_b) + sort_stack_3(stack_a);
	index = stack_b->head->index;
	if (index == 0)
		op += pa(stack_a, stack_b);
	else if (index == 1)
		op += pa(stack_a, stack_b) + sa(stack_a);
	else if (index == 2)
		op += ra(stack_a) + pa(stack_a, stack_b) + rra(stack_a) + rra(stack_a);
	else
		op += pa(stack_a, stack_b) + rra(stack_a);
	return (op);
}

static int	sort_stack_5(t_stack *stack_a, t_stack *stack_b)
{
	int	op;
	int	index;

	op = pb(stack_a, stack_b) + pb(stack_a, stack_b) + sort_stack_3(stack_a);
	while (stack_b)
	{
		index = stack_b->head->index;
		if (index == 0)
			op += pa(stack_a, stack_b);
		else if (index == 4)
			op += pa(stack_a, stack_b) + ra(stack_a);
		else if (index == 1)
			op += pa(stack_a, stack_b) + sa(stack_a);
		else if (index == 2)
			op += ra(stack_a) + pa(stack_a, stack_b) + sa(stack_a) + rra(stack_a);
		else
			op += rra(stack_a) + rra(stack_a) + pa(stack_a, stack_b) + rra(stack_a) + rra(stack_a);
	}
	return (op);
}

int	sort(t_stack *stack_a)
{
	int		operations;
	t_stack	*stack_b;

	stack_b = create_stack();
	operations = 0;

	if (stack_a->size == 2)
		operations += sort_stack_2(stack_a);
	else if (stack_a->size == 3)
		operations += sort_stack_3(stack_a);
	else if (stack_a->size == 4)
		operations += sort_stack_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		operations += sort_stack_5(stack_a, stack_b);
	else
		operations = k_sort(stack_a, stack_b);
	free_stack(stack_b);
	return (operations);
}
