/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:03:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/14 20:49:22 by jtivan-r         ###   ########.fr       */
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
t_stack		*create_stack(void);
void		*free_stack(t_stack *stack);
t_list		*push_to_stack(t_stack *stack, int val);
void		*pop_from_stack(t_stack *stack);

#endif /* stack.h */
