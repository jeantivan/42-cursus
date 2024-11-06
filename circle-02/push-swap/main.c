/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/06 18:47:23 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

#include "error.h"
#include "parser.h"

int main(int argc, char **argv)
{
	int	i;
	t_list	*values;

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
	values = parse_values(argv, argc);
	if (!values)
		return (print_error());
	print_parsed_values(values);
	return (0);
}
