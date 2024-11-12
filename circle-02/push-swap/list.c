/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:04:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/12 16:47:44 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	print_list(t_list *values)
{
	t_list	*temp;
	int		*num;

	temp = values;
	ft_printf("head -> ");
	while (temp)
	{
		num = (int *)temp->content;
		ft_printf("%d -> ", *num);
		temp = temp->next;
	}
	ft_printf("NULL \n");
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
