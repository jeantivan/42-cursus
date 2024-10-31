/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:02:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/16 19:48:32 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_test_char(void)
{
	int	test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with char ---" ANSI_COLOR_RESET "\n");
	test = printf("%c", 'a');
	printf("\nPrinting: 'a' test = %i\n", test);
	test = printf("%c", 65);
	printf("\nPrinting: 65 test = %i\n", test);
	test = printf("%c", 0);
	printf("\nPrinting: 0 test = %i\n", test);
	test = printf("%c", '\0');
	printf("\nPrinting: '\\0' test = %i\n", test);
	test = printf("%c", 4242);
	printf("\nPrinting: 4242 test = %i\n", test);
	test = printf("%c", -1);
	printf("\nPrinting: -1 test = %i\n", test);
	test = printf("%c", 128);
	printf("\nPrinting: 128 test = %i\n", test);
	test = printf("%c", 256);
	printf("\nPrinting: 256 test = %i\n", test);
	test = printf("%c", -128);
	printf("\nPrinting: -128 test = %i\n", test);
	test = printf("%c", -256);
	printf("\nPrinting: -256 test = %i\n", test);
	test = printf("%c", -200000);
	printf("\nPrinting: -200000 test = %i\n", test);
}
