/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:03:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/13 17:56:28 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct Stack
{
	t_list	*head;
	int		size;
}			Stack;
void		print_list(t_list *list);
t_list		*new_node(int val);
Stack		*create_stack(void);
Stack		*add_to_stack(Stack *stack, t_list *node);

#endif /* list.h */
