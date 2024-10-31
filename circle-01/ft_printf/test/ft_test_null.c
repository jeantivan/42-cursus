/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:02:11 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/17 18:48:01 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_test_null(void)
{
	int	test_char;
	//int	test_string;
	int	test_pointer;
	int	test_digit;
	int	test_int;
	int	test_u;
	int	test_x;
	int	test_X;

	printf(ANSI_COLOR_BLUE "\n --- Test printf behavior with NULL ---" ANSI_COLOR_RESET "\n");
	test_char = printf("%c", '\0');
	printf("\ntest_char = %i\n", test_char);
/* 	test_string = printf("%s", NULL);
	printf("\ntest_string = %i\n", test_string); */
	test_pointer = printf("%p", NULL);
	printf("\ntest_pointer = %i\n", test_pointer);
	test_digit = printf("%d", 0);
	printf("\ntest_digit = %i\n", test_digit);
	test_int = printf("%i", 0);
	printf("\ntest_int = %i\n", test_int);
	test_u = printf("%u", 0);
	printf("\ntest_u = %i\n", test_u);
	test_x = printf("%x", 0);
	printf("\ntest_u = %i\n", test_x);
	test_X = printf("%X", 0);
	printf("\ntest_X = %i\n", test_X);
}
