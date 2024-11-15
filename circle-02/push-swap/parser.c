/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:42:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/15 16:52:30 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "stack.h"
#include "utils.h"
#include <limits.h>

static int	val_el(char *el)
{
	int	i;

	i = 0;
	if (!ft_isdigit(el[i]) && (el[i] != '-' && el[i] != '+'))
		return (0);
	i++;
	while (el[i])
	{
		if (!ft_isdigit(el[i]))
			return (0);
		i++;
	}
	if (ft_atoi(el) > INT_MAX)
		return (0);
	else if (ft_atoi(el) < INT_MIN)
		return (0);
	return (1);
}

static int	check_dup(t_list *head, int new_val)
{
	t_list	*temp;

	if (head)
	{
		temp = head;
		while (temp)
		{
			if (*((int *)(temp->content)) == new_val)
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}

t_stack	*parse_values(char **argv, int argc)
{
	t_stack	*stack;
	int		i;
	int		j;
	char	**input;

	stack = create_stack();
	if (!stack)
		return (NULL);
	i = argc - 1;
	while (i >= 1)
	{
		input = ft_split(argv[i--], ' ');
		j = arr_length(input) - 1;
		while (j >= 0)
		{
			if (!val_el(input[j]) || check_dup(stack->head, ft_atoi(input[j])))
			{
				ft_free_split(input);
				return (free_stack(stack));
			}
			push_to_stack(stack, create_node(ft_atoi(input[j--])));
		}
		ft_free_split(input);
	}
	return (stack);
}
