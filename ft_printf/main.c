/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:39:36 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/16 16:10:25 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_test_base(void)
{
	int	test_char;
	int	test_string;
	int	test_pointer;
	int	test_digit;
	int	test_int;
	int	test_u;
	int	test_x;
	int	test_X;
	int	x;

	x = 10;
	test_char = printf("%c", 'A');
	printf("\ntest_char = %i\n", test_char);
	test_string = printf("%s", "Hola mundo!");
	printf("\ntest_string = %i\n", test_string);
	test_pointer = printf("%p", &x);
	printf("\ntest_pointer = %i\n", test_pointer);
	test_digit = printf("%d", 123);
	printf("\ntest_digit = %i\n", test_digit);
	test_int = printf("%i", 12324);
	printf("\ntest_int = %i\n", test_int);
	test_u = printf("%u", 987);
	printf("\ntest_u = %i\n", test_u);
	test_x = printf("%x", 9999);
	printf("\ntest_u = %i\n", test_x);
	test_X = printf("%X", 5555);
	printf("\ntest_X = %i\n", test_X);
}
int	main(void)
{
	ft_test_base();
	return (0);
}
