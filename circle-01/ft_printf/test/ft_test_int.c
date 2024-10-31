/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:44:54 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 18:44:55 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_test_int(void)
{
		int test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with int ---" ANSI_COLOR_RESET "\n");
	test = printf("%i", 1);
	printf("\nPrinting: 1 test = %i\n", test);
	test = printf("%i", 0);
	printf("\nPrinting: 0 test = %i\n", test);
	test = printf("%i", -20);
	printf("\nPrinting: -20 test = %i\n", test);
	test = printf("%i", 2147483647);
	printf("\nPrinting: 2147483647 test = %i\n", test);
	test = printf("%i", -2147483647);
	printf("\nPrinting: -2147483648 test = %i\n", test);
	test = printf("%u", 022);
	printf("\nPrinting: 022 test = %i\n", test);
	/* test = printf("%i", 2147483650);
	printf("\nPrinting: 2147483650 test = %i\n", test);
	test = printf("%i", -2147483650);
	printf("\nPrinting: -2147483650 test = %i\n", test);
	test = printf("%i", (int)NULL);
	printf("\nPrinting: (int)NULL test = %i\n", test); */
}
