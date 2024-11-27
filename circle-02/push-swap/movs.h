#ifndef MOVS_H
# define MOVS_H

# include "ft_printf/ft_printf.h"
# include "stack.h"

int sa(t_stack *stack_a);
int sb(t_stack *stack_b);
int ss(t_stack *stack_a, t_stack *stack_b);
int pa(t_stack *stack_a, t_stack *stack_b);
int pb(t_stack *stack_a, t_stack *stack_b);
int ra(t_stack *stack_a);
int rb(t_stack *stack_b);
int rr(t_stack *stack_a, t_stack *stack_b);
int rra(t_stack *stack_a);
int rrb(t_stack *stack_b);
int rrr(t_stack *stack_a, t_stack *stack_b);

#endif
