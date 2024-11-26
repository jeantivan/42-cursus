/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/26 19:16:38 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "operations.h"
#include "parser.h"
#include "sort.h"
#include "stack.h"
#include "utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		operations;

	if (argc <= 1)
		return (print_error());
	stack_a = parse_values(argv, argc);
	if (!stack_a)
		return (print_error());
	if (!is_sorted(stack_a))
	{
		ft_printf("Stack a is not sorted\n");
		show_stack(stack_a);
		ft_printf("\nSorting...\n");
		operations = sort_stack(stack_a);
		show_stack(stack_a);
		ft_printf("Stack sorted in %i operations\n", operations);
	}
	else
	{
		ft_printf("Stack a is sorted\n");
		show_stack(stack_a);
	}
	free_stack(stack_a);
	return (0);
}
