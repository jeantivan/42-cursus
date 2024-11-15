/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:35:13 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/15 17:11:32 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "sort.h"
#include "utils.h"

int	sort_stack(t_stack *stack_a)
{
	int		operations;
	t_list	*temp_node;
	t_stack	*stack_b;

	stack_b = create_stack();
	operations = 0;
	while (stack_a->size != 0)
	{
		temp_node = pop_from_stack(stack_a);
		operations++;
		while (stack_b->size != 0
			&& *((int *)stack_b->head->content) > *((int *)temp_node->content))
		{
			push_to_stack(stack_a, pop_from_stack(stack_b));
			operations += 2;
		}
		push_to_stack(stack_b, temp_node);
		operations++;
	}
	while (stack_b->size != 0)
	{
		push_to_stack(stack_a, pop_from_stack(stack_b));
		operations += 2;
	}
	free_stack(stack_b);
	return (operations);
}
