/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:42:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/13 18:15:42 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "list.h"
#include "utils.h"
#include <limits.h>

int	valid_el(char *el)
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

int	valid_input(char *input)
{
	char	**inputs;
	int		i;

	i = 0;
	inputs = ft_split(input, ' ');
	if (!inputs)
		return (0);
	while (inputs[i])
	{
		if (!valid_el(inputs[i]))
		{
			ft_free_split(inputs);
			return (0);
		}
		i++;
	}
	ft_free_split(inputs);
	return (1);
}

int	check_duplicate(t_list *head, int new_val)
{
	t_list	*temp;

	if (head)
	{
		temp = head;
		while (temp)
		{
			if (*((int *)(temp->content)) == new_val)
			{
				ft_lstclear(&head, free);
				return (1);
			}
			temp = temp->next;
		}
	}
	return (0);
}

t_list	*parse_values(char **argv, int argc)
{
	t_list	*head;
	int		i;
	int		j;
	char	**input;

	(void)argc;
	i = 1;
	while (argv[i])
	{
		j = 0;
		input = ft_split(argv[i], ' ');
		while (input[j])
		{
			if (i == 1 && j == 0)
			{
				head = new_node(ft_atoi(input[j]));
				if (!head)
					return (ft_free_split(input));
				j++;
				continue ;
			}
			if (check_duplicate(head, ft_atoi(input[j])))
				return (ft_free_split(input));
			ft_lstadd_back(&head, new_node(ft_atoi(input[j++])));
		}
		ft_free_split(input);
		i++;
	}
	return (head);
}
