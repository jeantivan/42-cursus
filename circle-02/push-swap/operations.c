/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:29:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/15 15:03:13 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

void	swap(t_stack *stack)
{
	t_list	*temp_n;

	if (stack->size <= 1)
		return ;
	temp_n = stack->head;
	stack->head = stack->head->next;
	temp_n->next = stack->head->next;
	stack->head->next = temp_n;
}

void	push(t_stack *stack_1, t_stack *stack_2)
{
	int	*content;

	if (!stack_1->head)
		return ;
	content = (int *)pop_from_stack(stack_1);
	push_to_stack(stack_2, *content);
	ft_safe_free((void **)&content);
}

void	rotate(t_stack *stack)
{
	t_list	*temp_node;

	if (stack->size <= 1)
		return ;
	temp_node = stack->head;
	stack->head = temp_node->next;
	temp_node->next = NULL;
	ft_lstadd_back(&stack->head, temp_node);
}

void	reverse_r(t_stack *stack)
{
	t_list	*last_n;
	t_list	*temp_n;

	if (stack->size <= 1)
		return ;
	temp_n = stack->head;
	while (temp_n->next->next)
		temp_n = temp_n->next;
	last_n = temp_n->next;
	temp_n->next = NULL;
	ft_lstadd_front(&stack->head, last_n);
}
int	is_sorted(t_stack *stack)
{
	t_list	*temp_n;

	temp_n = stack->head;
	while (temp_n->next)
	{
		if (*((int *)temp_n->content) > *((int *)temp_n->next->content))
			return (0);
		temp_n = temp_n->next;
	}
	return (1);
}
