/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:04:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/14 20:43:15 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"

void	show_stack(t_stack *stack)
{
	t_list	*temp;
	int		*num;

	temp = stack->head;
	ft_printf("head -> ");
	while (temp)
	{
		num = (int *)temp->content;
		ft_printf("%d -> ", *num);
		temp = temp->next;
	}
	ft_printf("NULL \n");
	ft_printf("Stack size: %i\n", stack->size);
}

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

t_list	*push_to_stack(t_stack *stack, int val)
{
	int		*num;
	t_list	*node;

	if (!stack)
		return (NULL);
	num = (int *)malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = val;
	node = ft_lstnew(num);
	if (!node)
		return (NULL);
	ft_lstadd_front(&stack->head, node);
	stack->size++;
	return (node);
}

void	*pop_from_stack(t_stack *stack)
{
	t_list	*node;
	void	*content;

	if (!stack->head)
		return (NULL);
	node = stack->head;
	content = node->content;
	stack->head = node->next;
	stack->size--;
	ft_safe_free((void **)&node);
	return (content);
}