#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		i;

	if (ac <= 1)
		return (1);
	stack_a = parse_values(av, ac);
	if (!stack_a)
		return (print_error());
	stack_b = create_stack();
	if (!stack_b)
	{
		free_stack(stack_a);
		return (1);
	}
	line = get_next_line(0);
	i = 0;
	while (line)
	{
		ft_printf("Exe %s\n", line);
		handle_mov(stack_a, stack_b, line);
		gnl_safe_free((void **)&line);
		line = get_next_line(0);
		i++;
	}
	ft_printf("Se hicieron %i movimientos\n", i);
	show_stack(stack_a);
	show_stack(stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	gnl_safe_free((void **)&line);
	return (0);
}
