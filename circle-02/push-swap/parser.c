/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:42:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/04 19:53:04 by jtivan-r         ###   ########.fr       */
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

t_list	*parse_values(char **argv, size_t size)
{
	t_list	*head;
	size_t	i;
	t_list	*temp;

	i = 1;
	if (valid_el(argv[i]))
		head = ft_lstnew(ft_strdup(argv[i++]));
	else
		return (NULL);
	while (i < size)
	{
		if (!valid_el(argv[i]))
		{
			ft_lstclear(&head, free);
			return (NULL);
		}
		temp = ft_lstnew(ft_strdup(argv[i]));
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}

void	print_parsed_values(t_list *values)
{
	t_list *temp;

	temp = values;
	while (temp)
	{
		ft_printf("%s\n", temp->content);
		temp = temp->next;
	}
}
