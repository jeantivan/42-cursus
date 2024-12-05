/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:16:23 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/05 17:55:37 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "base.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>

/* Algorithm aux */
int	sort_stack_2(t_stack *stack, char letter);
int	sort_stack_3(t_stack *stack, char letter);
int	best_rotate(int pos, t_stack *stack, char letter);

/* Algorithm */
int	small_sort(t_stack *stack_a, t_stack *stack_b);
int	k_sort(t_stack *stack_a, t_stack *stack_b);
int	sort(t_stack *stack_a);

#endif /* push_swap.h */
