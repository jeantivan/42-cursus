/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   made_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:27:08 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/05 19:28:53 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	handle_swap(t_stack *stack_a, t_stack *stack_b, char *mov)
{
	int	op;

	op = 0;
	if (ft_strncmp(mov, "sa\n", 5))
		op += sx(stack_a, 'a', true);
	else if (ft_strncmp(mov, "sb\n", 5))
		op += sx(stack_b, 'b', true);
	else
		op += ss(stack_a, stack_b, true);
	return (op);
}

int	handle_push(t_stack *stack_a, t_stack *stack_b, char *mov)
{
	int	op;

	op = 0;
	if (ft_strncmp(mov, "pa\n", 5))
		op += px(stack_a, stack_b, 'a', true);
	else if (ft_strncmp(mov, "pb\n", 5))
		op += px(stack_a, stack_b, 'b', true);
	return (op);
}

int	handle_rotate(t_stack *stack_a, t_stack *stack_b, char *mov)
{
	int	op;

	op = 0;
	if (ft_strncmp(mov, "ra\n", 5))
	{
		ft_printf("Hola 1 %c\n", ft_strncmp(mov, "ra\n", 5));
		op += rx(stack_a, 'a', true);
	}
	else if (ft_strncmp(mov, "rb\n", 5))
	{

		op += rx(stack_b, 'b', true);
	}
	else if (ft_strncmp(mov, "rr\n", 5))
	{
		op += rr(stack_a, stack_b, true);
	}
	else if (ft_strncmp(mov, "rra\n", 5))
	{
		op += rrx(stack_a, 'a', true);
	}
	else if (ft_strncmp(mov, "rrb\n", 5))
	{
		op += rrx(stack_b, 'b', true);
	}
	else
	{

	}
	return (op);
}

int	handle_mov(t_stack *stack_a, t_stack *stack_b, char *mov)
{
	int		op;

	op = 0;
	if (mov[0] == 's')
		op += handle_swap(stack_a, stack_b, mov);
	else if (mov[0] == 'p')
		op += handle_push(stack_a, stack_b, mov);
	else
		op += handle_rotate(stack_a, stack_b, mov);
	return (op);
}
