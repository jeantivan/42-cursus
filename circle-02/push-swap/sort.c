#include "ft_printf/ft_printf.h"
#include "sort.h"
#include "utils.h"
#include "movs.h"
#include "operations.h"

int	sort_stack_3(t_stack *stack)
{
	t_list *node;
	int		op;
	int	node1_val, node2_val, node3_val;

	op = 0;
	if (!stack->head || stack->size < 3)
		return (-1);
	node = stack->head;
	node1_val = peek(node);
	node2_val = peek(node->next);
	node3_val = peek(node->next->next);

	if ((node1_val > node2_val) && (node2_val < node3_val) && (node1_val > node3_val))
		op+= ra(stack);
	else if ((node1_val > node2_val) && (node1_val < node3_val) && (node2_val < node3_val))
		op += sa(stack);
	else if ((node1_val > node2_val) && (node1_val > node3_val) && (node2_val > node3_val))
		op += ra(stack) + sa(stack);
	else if ((node1_val < node2_val) && (node1_val < node3_val) && (node2_val > node3_val))
		op += rra(stack) + sa(stack);
	return (op);
}

int	sort_turk(t_stack *stack_a, t_stack *stack_b)
{
	int op = 0;
	int count;
	int stack_b_max = 0;
	int stack_b_min = 0;
	int current;

	while(stack_a->size)
	{
		if (stack_b->size == 0)
		{
			op += pb(stack_a, stack_b);
			stack_b_max = peek(stack_b->head);
			stack_b_min = peek(stack_b->head);
		}
		else
		{
			count = 0;
			current = peek(stack_a->head);
			if (!(current > stack_b_max) && !(current < stack_b_min))
			{
				while(current < peek(stack_b->head))
					count += rb(stack_b);
				op += pb(stack_a, stack_b) + count + count;
				while(count)
					count -= rrb(stack_b);
			} else if (current < stack_b_min)
			{
				op += pb(stack_a, stack_b) + rb(stack_b);
				stack_b_min = current;
			} else
			{
				op += pb(stack_a, stack_b);
				stack_b_max = current;
			}
		}
	}
	while (stack_b->size)
		op += pa(stack_a, stack_b);
	return (op);
}

int	sort(t_stack *stack_a)
{
	int		operations;
	t_list	*temp_node;
	t_stack	*stack_b;

	stack_b = create_stack();
	operations = 0;

	if (stack_a->size == 2)
	{
		temp_node = stack_a->head;
		if (peek(temp_node) > peek(temp_node->next))
			operations += sa(stack_a);
	} else if (stack_a->size == 3)
		operations += sort_stack_3(stack_a);
	else
		operations = sort_1(stack_a, stack_b);
	free_stack(stack_b);
	return (operations);
}
