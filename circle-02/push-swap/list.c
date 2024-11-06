/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:04:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/06 19:15:13 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	print_list(t_list *values)
{
	t_list	*temp;
	int		*num;

	temp = values;
	while (temp)
	{
		num = (int *)temp->content;
		ft_printf("%d\n", *num);
		temp = temp->next;
	}
}

t_list	*new_node(int val)
{
	int		*num;
	t_list	*node;

	num = (int *)malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = val;
	node = ft_lstnew(num);
	return (node);
}
