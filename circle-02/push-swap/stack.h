/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:03:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/26 20:24:32 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*head;
	int		size;
}			t_stack;
void		show_stack(t_stack *stack);
void		*free_stack(t_stack *stack);
t_stack		*create_stack(void);
t_list		*push_to_stack(t_stack *stack, t_list *node);
t_list		*pop_from_stack(t_stack *stack);
t_list		*create_node(int val);
int			peek(t_list *node);

#endif /* stack.h */
