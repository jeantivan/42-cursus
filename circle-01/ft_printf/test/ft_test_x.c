/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:46:44 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 18:46:45 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_test_x(void)
{
	int	test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with x ---" ANSI_COLOR_RESET "\n");
	test = printf("%x", 1);
	printf("\nPrinting: 1 test = %i\n", test);
	test = printf("%x", 0);
	printf("\nPrinting: 0 test = %i\n", test);
	test = printf("%x", 256);
	printf("\nPrinting: 256 test = %i\n", test);
	test = printf("%x", 2147483647);
	printf("\nPrinting: 2147483647 test = %i\n", test);
	test = printf("%x", -2147483647);
	printf("\nPrinting: -2147483648 test = %i\n", test);
	test = printf("%x", 022);
	printf("\nPrinting: 022 test = %i\n", test);
}
