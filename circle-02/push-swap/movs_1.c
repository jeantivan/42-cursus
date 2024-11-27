#include "operations.h"
#include "movs.h"

int sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return (1);
}

int sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return (1);
}

int ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return (2);
}

int pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
	return (1);
}

int pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
	return (1);
}
int ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return (1);
}
int rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return (1);
}

int rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return (2);
}

int rra(t_stack *stack_a)
{
	reverse_r(stack_a);
	ft_printf("rra\n");
	return (1);
}

int rrb(t_stack *stack_b)
{
	reverse_r(stack_b);
	ft_printf("rrb\n");
	return (1);
}
int rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_r(stack_a);
	reverse_r(stack_b);
	ft_printf("rrr\n");
	return (2);
}
