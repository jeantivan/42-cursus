/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:46:27 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 17:57:22 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack *stack_a)
{
	int		operations;
	t_stack	*stack_b;

	stack_b = create_stack();
	operations = 0;
	if (stack_a->size == 2)
		operations += sort_stack_2(stack_a, 'a');
	else if (stack_a->size == 3)
		operations += sort_stack_3(stack_a, 'a');
	else if (stack_a->size == 4)
		operations += sort_stack_4(stack_a, stack_b);
	else if (stack_a->size == 5)
		operations += sort_stack_5(stack_a, stack_b);
	else
		operations = k_sort(stack_a, stack_b);
	free_stack(stack_b);
	return (operations);
}
