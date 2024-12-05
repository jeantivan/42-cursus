/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:36:56 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/05 19:10:35 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack_2(t_stack *stack, char letter)
{
	if (letter != 'a' && letter != 'b')
		exit(EXIT_FAILURE);
	if (peek(stack->head) > peek(stack->head->next))
		return (sx(stack, letter, true));
	return (0);
}

int	sort_stack_3(t_stack *stack, char letter)
{
	int	op;
	int	n1;
	int	n2;
	int	n3;

	if ((letter != 'a' && letter != 'b'))
		exit(EXIT_FAILURE);
	if (!stack->head || stack->size < 3)
		return (-1);
	op = 0;
	n1 = peek(stack->head);
	n2 = peek(stack->head->next);
	n3 = peek(stack->head->next->next);
	if (n1 > n2 && n1 > n3)
		op += rx(stack, letter, true);
	else if (n1 < n2 && n3 < n2)
		op += rrx(stack, letter, true);
	if (peek(stack->head) > peek(stack->head->next))
		op += sx(stack, letter, true);
	return (op);
}

int	best_rotate(int pos, t_stack *stack, char letter)
{
	int	op;

	op = 0;
	if (pos <= stack->size / 2)
	{
		while (pos--)
			op += rx(stack, letter, true);
	}
	else
	{
		pos = stack->size - pos;
		while (pos--)
			op += rrx(stack, letter, true);
	}
	return (op);
}
