/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:42:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 20:15:20 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	if (ft_atoi(el) != ft_atol(el))
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

static t_list	*find_min(t_list *list)
{
	long int	curr_min;
	t_list		*curr_node;
	t_list		*min_node;

	curr_node = list;
	min_node = NULL;
	curr_min = LONG_MAX;
	while (curr_node)
	{
		if (peek(curr_node) < curr_min && curr_node->index == -1)
		{
			min_node = curr_node;
			curr_min = peek(min_node);
		}
		curr_node = curr_node->next;
	}
	return (min_node);
}

static t_stack	*set_indexes(t_stack *stack)
{
	int		switcher;
	int		index;
	t_list	*min_node;

	switcher = 1;
	index = 0;
	if (stack->size <= 0)
		return (stack);
	while (switcher)
	{
		switcher = 0;
		min_node = find_min(stack->head);
		if (min_node && min_node->index == -1)
		{
			min_node->index = index++;
			switcher = 1;
		}
	}
	return (stack);
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
	return (set_indexes(stack));
}
