/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:35:13 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/15 15:47:51 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "sort.h"
#include "utils.h"

int	sort_stack(t_stack *stack_a)
{
	int		operations;
	int		pase;
	int		control_a;
	int		control_b;
	int		*temp_node_c;
	t_stack	*stack_b;

	stack_b = create_stack();
	operations = 0;
	control_a = 0;
	control_b = 0;
	pase = 0;
	while (stack_a->size != 0 || control_a < 10000)
	{
		ft_printf("\nPase = %i\n", pase++);
		temp_node_c = (int *)pop_from_stack(stack_a);
		control_a++;
		ft_printf("stack_a\n");
		show_stack(stack_a);
		ft_printf("stack_b\n");
		show_stack(stack_b);
		ft_printf("temp_n_c = %i\n", *temp_node_c);
		while (stack_b->size != 0
			&& *((int *)stack_b->head->content) > *temp_node_c)
		{
			ft_printf("Entrando aquí\n");
			ft_printf("stack_a\n");
			show_stack(stack_a);
			ft_printf("stack_b\n");
			show_stack(stack_b);
			push_to_stack(stack_a, *temp_node_c);
			pop_from_stack(stack_b);
			control_a++;
		}
		push_to_stack(stack_b, *temp_node_c);
		control_a++;
		ft_printf("control_a : %i\n", control_a);
	}
	while (stack_b->size != 0 || control_b < 10000)
	{
		temp_node_c = pop_from_stack(stack_b);
		push_to_stack(stack_a, *temp_node_c);
		control_b += 2;
		ft_printf("control_b: %i\n", control_b);
	}
	free_stack(stack_b);
	operations = control_a + control_b;
	return (operations);
}
