/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:42:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/06 19:15:16 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "utils.h"

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
	return (1);
}

int	valid_input(char *input)
{
	char	**inputs;
	int		i;

	i = 0;
	inputs = ft_split(input, ' ');
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



t_list	*parse_values(char **argv, size_t size)
{
	t_list	*head;
	size_t	i;
	t_list	*temp;

	i = 1;
	head = new_node(ft_atoi(argv[i]));
	if (!head)
		return (NULL);
	while (i < size)
	{
		if (!valid_el(argv[i]))
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		temp = new_node(ft_atoi(argv[i]));
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}
