/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:45:42 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 18:45:43 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_test_p(void)
{
	int test;
	int	p_int = 1;
	char *p_s = "Hola";
	char p_c = 'a';

	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior with p ---" ANSI_COLOR_RESET "\n");
	test = printf("%p", (void *)&p_int);
	printf("\nPrinting: &p_int test = %i\n", test);
	test = printf("%p", (void *)&p_s);
	printf("\nPrinting: (void *)&p_s test = %i\n", test);
	test = printf("%p", (void *)&p_c);
	printf("\nPrinting: (void *)&p_c test = %i\n", test);
	test = printf("%p", NULL);
	printf("\nPrinting: NULL test = %i\n", test);

}
