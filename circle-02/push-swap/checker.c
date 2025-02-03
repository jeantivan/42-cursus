/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:00:47 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/03 15:13:47 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_movs(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	char	*line;

	line = get_next_line(0);
	i = 0;
	while (line)
	{
		handle_mov(stack_a, stack_b, line);
		gnl_safe_free((void **)&line);
		line = get_next_line(0);
		i++;
	}
}

void	check_status(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (1);
	stack_a = parse_values(av, ac);
	if (!stack_a)
		return (print_error());
	stack_b = create_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		return (1);
	}
	read_movs(stack_a, stack_b);
	check_status(stack_a, stack_b);
	free_stack(stack_a);
	return (0);
}
