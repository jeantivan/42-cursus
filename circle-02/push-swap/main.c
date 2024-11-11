/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/11 19:04:29 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "utils.h"
#include "error.h"
#include "parser.h"
#include "list.h"

int main(int argc, char **argv)
{
	int	i;
	//t_list	*values;
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
	/* values = parse_values(argv, argc);
	if (!values)
		return (print_error());
	print_list(values); */
	return (0);
}
