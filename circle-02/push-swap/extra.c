/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:27:50 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/03 22:42:02 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	show_stack(t_stack *stack)
{
	t_list	*temp;
	int		*num;

	temp = stack->head;
	ft_printf("head -> ");
	while (temp)
	{
		num = (int *)temp->content;
		ft_printf("i: %d, %d -> \n", temp->index, *num);
		temp = temp->next;
	}
	ft_printf("NULL \n");
	ft_printf("Stack size: %i\n", stack->size);
}


int	peek(t_list *node)
{
	int	val;

	val = *((int *)node->content);
	return (val);
}
