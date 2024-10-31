/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:45:56 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 18:45:57 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_test_string(void)
{
	int	test;

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with string ---" ANSI_COLOR_RESET "\n");
	test = printf("%s", "Hola mundo!");
	printf("\nPrinting: 'Hola mundo' test = %i\n", test);
	test = printf("%s", "");
	printf("\nPrinting: '' test = %i\n", test);
	/* test = printf("%s", (char *)NULL);
	printf("\nPrinting: NULL test = %i\n", test); */
	/* test = printf("%s", (char *)0);
	printf("\nPrinting (char *)0, test = %i\n", test); */

}
