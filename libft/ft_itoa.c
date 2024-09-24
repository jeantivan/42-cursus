/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:07:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/24 19:07:01 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int	ft_n_digits(int n)
{
	int	digits;

	digits = 1;
	while (n / 10 != 0)
	{
		digits++;
		n /= 10;
	}
	return digits;
}

char	*ft_itoa(int n)
{
	size_t		size;
	int			n_is_negative;
	long int	new_n;
	char 		*str = "itoa";

	new_n = n + 0;
	size = ft_n_digits(n);
	n_is_negative = ft_is_negative(n);
	if (n_is_negative) {
		size++;
	}
	/* TODO: Ya se tiene la longitud final de a string
		1. Hay que alocar la memoría para la string.
		2. Si el n es negativo agregar el - al inicio del string y n *= -1;
		3. Agregar caracter a caracter el primer dígito de int
	*/
	return (str);
}
