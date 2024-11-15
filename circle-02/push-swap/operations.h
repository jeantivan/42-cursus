/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:30:25 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/14 22:35:41 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft/libft.h"
# include "stack.h"

void  swap(t_stack *stack);
void  push(t_stack *stack_1, t_stack *stack_2);
void  rotate(t_stack *stack);
void  reverse(t_stack *stack);

#endif /* operations.h */