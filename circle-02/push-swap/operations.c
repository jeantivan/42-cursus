/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:29:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/14 23:41:03 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

void	swap(t_stack *stack)
{
	t_list *temp_n;

	if (stack->size <= 1)
		return ;
	temp_n = stack->head;
	stack->head = stack->head->next;
	temp_n->next = stack->head->next;
	stack->head->next = temp_n;
}

void	push(t_stack *stack_1, t_stack *stack_2)
{
	int *content;

	if (!stack_1->head)
		return ;
	content = (int *)pop_from_stack(stack_1);
	push_to_stack(stack_2, *content);
	ft_safe_free((void **)&content);
}
