/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/03 15:20:10 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc <= 1)
		return (1);
	stack_a = parse_values(argv, argc);
	if (!stack_a)
		return (print_error());
	if (!is_sorted(stack_a))
		sort(stack_a);
	free_stack(stack_a);
	return (0);
}
