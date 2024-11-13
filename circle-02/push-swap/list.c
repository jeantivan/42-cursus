/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:04:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/13 18:12:24 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "utils.h"

void	show_stack(Stack *stack)
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
}

t_list	*new_node(int val)
{
	int		*num;
	t_list	*node;

	num = (int *)malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = val;
	node = ft_lstnew(num);
	return (node);
}
Stack	*add_to_stack(Stack *stack, t_list *node)
{
	if (!stack || !node)
		return (NULL);
	ft_lstadd_front(&stack->head, node);
	stack->size++;
	return (stack);
}
Stack	*create_stack(void)
{
	Stack	*stack;

	stack = (Stack *)malloc(sizeof(Stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}
