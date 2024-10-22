/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:39:36 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 21:57:53 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft/libft.h"
#include <limits.h>

int	main(void)
{
	int	counter;
	/* int	x;
	unsigned int ux;

	x = -4242;
	ux = (unsigned int)x;
	counter = ft_printf("Testing my own \n Porcentaje %%, c: %c seguimos, d: %d, i: %i, u: %u, p: %p, x: %x, X: %X", -128, 42, -402021, ux, &x, x, x);
	printf("\nPrinted %i chars \n", counter);
	counter = printf("Testing my own \n Porcentaje %%, c: %c seguimos, d: %d, i: %i, u: %u, p: %p, x: %x, X: %X", -128, 42, -402021, ux, &x, x, x);
	printf("\nPrinted %i chars \n", counter); */
	counter = ft_printf(" %i ", -1);
	printf("\nPrinted %i chars \n", counter);

	printf("\nPrinted %i chars \n", printf(" %i ", INT_MIN));

	return (0);
}
