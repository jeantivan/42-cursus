/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_void.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:46:30 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 18:46:31 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_test_void(void)
{
	int	test;
	int	i;

	i = 10;
	printf(ANSI_COLOR_BLUE "\n--- Test printf behavior without passing the vars ---" ANSI_COLOR_RESET "\n");
	test = printf("Void: number %i", 1);
	printf("\nPrinting number void test = %i\n", test);
	test = printf("Void: string %s", "hola");
	printf("\nPrinting string void test = %i\n", test);
	test = printf("Void: %%p %p", &i);
	printf("\nPrinting pointer void test = %i\n", test);
	test = printf("Void: digit %d", 1000);
	printf("\nPrinting number void test = %i\n", test);
}
