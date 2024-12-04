/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:16:23 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 20:04:10 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

/* Stack */
typedef struct s_stack
{
	t_list	*head;
	int		size;
}			t_stack;

void		*free_stack(t_stack *stack);
t_stack		*create_stack(void);
t_list		*push_to_stack(t_stack *stack, t_list *node);
t_list		*pop_from_stack(t_stack *stack);
t_list		*create_node(int val);

/* Stack operations */
void		swap(t_stack *stack);
void		push(t_stack *stack_1, t_stack *stack_2);
void		rotate(t_stack *stack);
void		reverse_r(t_stack *stack);

/* Movements */
int			sx(t_stack *stack, char letter);
int			px(t_stack *stack_a, t_stack *stack_b, char letter);
int			rx(t_stack *stack, char letter);
int			rrx(t_stack *stack, char letter);
int			ss(t_stack *stack_a, t_stack *stack_b);
int			rr(t_stack *stack_a, t_stack *stack_b);
int			rrr(t_stack *stack_a, t_stack *stack_b);


/* Algorithm aux */
int			sort_stack_2(t_stack *stack, char letter);
int			sort_stack_3(t_stack *stack, char letter);
int			best_rotate(int pos, t_stack *stack, char letter);

/* Algorithm */
int			small_sort(t_stack *stack_a, t_stack *stack_b);
int			k_sort(t_stack *stack_a, t_stack *stack_b);
int			sort(t_stack *stack_a);

/* Extra */
int			peek(t_list *node);
void		show_stack(t_stack *stack);
int			is_sorted(t_stack *stack);

/* Error */
int			print_error(void);

/* Parser */
t_stack		*parse_values(char **argv, int argc);

/* Utils */
void		*ft_safe_free(void **ptr);
void		*ft_free_split(char **splited);
int			arr_length(char **arr);
long int	ft_atol(const char *ptr);
int			ft_sqrt(int num);

#endif /* push_swap.h */
