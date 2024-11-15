/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/14 23:41:23 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "stack.h"
#include "parser.h"
#include "utils.h"
#include "operations.h"
#include <stdio.h>

void	test_swap(t_stack *stack)
{
	ft_printf("---- Testing swap -----\n");
	show_stack(stack);
	ft_printf("\n");
	swap(stack);
	show_stack(stack);
	ft_printf("\n");
	swap(stack);
	show_stack(stack);
	ft_printf("\n");
}

void	test_push(t_stack *stack_1, t_stack *stack_2)
{
	ft_printf("---- Testing swap -----\n");
	show_stack(stack_1);
	show_stack(stack_2);
	ft_printf("--- Pushing two times from stack_a to stack_b\n");
	push(stack_1, stack_2);
	push(stack_1, stack_2);
	show_stack(stack_1);
	show_stack(stack_2);
	ft_printf("--- Pushing two times from stack_b to stack_a\n");
	push(stack_2, stack_1);
	push(stack_2, stack_1);
	show_stack(stack_1);
	show_stack(stack_2);
	ft_printf("--- Pushing one more time from stack_b to stack_a\n");
	push(stack_2, stack_1);
	show_stack(stack_1);
	show_stack(stack_2);
	ft_printf("--- Pushing one more time from stack_b to stack_a\n");
	push(stack_2, stack_1);
	show_stack(stack_1);
	show_stack(stack_2);
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (print_error());
	stack_a = parse_values(argv, argc);
	stack_b = create_stack();
	if(!stack_a)
		return (print_error());
	if (!stack_b)
	{
		free_stack(stack_a);
		return (print_error());
	}
	test_swap(stack_a);
	test_push(stack_a, stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
