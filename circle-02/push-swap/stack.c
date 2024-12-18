/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:04:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/03 23:14:07 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

void	*free_stack(t_stack *stack)
{
	ft_lstclear(&stack->head, free);
	return (ft_safe_free((void **)&stack));
}

t_list	*create_node(int val)
{
	int		*num;
	t_list	*node;

	num = (int *)malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = val;
	node = ft_lstnew(num);
	node->index = -1;
	return (node);
}

t_list	*push_to_stack(t_stack *stack, t_list *node)
{
	if (!stack)
		return (NULL);
	if (!node)
		return (NULL);
	ft_lstadd_front(&stack->head, node);
	stack->size++;
	return (node);
}

t_list	*pop_from_stack(t_stack *stack)
{
	t_list	*node;

	if (!stack->head)
		return (NULL);
	node = stack->head;
	stack->head = node->next;
	stack->size--;
	node->next = NULL;
	return (node);
}
