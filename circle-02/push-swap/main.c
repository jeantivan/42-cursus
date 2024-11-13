/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/13 18:05:29 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "list.h"
#include "parser.h"
#include "utils.h"
#include <stdio.h>

int	main(void)
{
	Stack	*stack;
	t_list	*temp;

	stack = create_stack();
	ft_printf("Stack size: %i\n", stack->size);
	add_to_stack(stack, new_node(12));
	temp = stack->head;
	while (temp)
	{
		printf("%i\n", *((int *)temp->content));
		temp = temp->next;
	}
	ft_printf("Stack size: %i\n", stack->size);
	return (0);
}

/* int main(int argc, char **argv)
{
	int	i;
	t_list	*values;
	//char	**input;
	size_t	count;

	if (argc <= 1)
		return (print_error());

	i = 1;
	while (argv[i])
	{
		if (!valid_input(argv[i]))
		{
			ft_printf("Invalid input %s\n", argv[i]);
			return (print_error());
		}
		i++;
	}
	count = count_elements(argv);
	printf("N of elements: %zu\n", count);
	values = parse_values(argv);
	if (!values)
		return (print_error());
	print_list(values);
	ft_lstclear(&values, free);
	return (0);
} */
