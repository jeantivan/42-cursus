/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:43:33 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 16:38:27 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_digits(unsigned int nbr)
{
	int	digits;

	digits = 1000000000;
	while (nbr / digits == 0)
		digits = digits / 10;
	return (digits);
}

int	ft_putnbr(int nbr)
{
	int	tot;
	int	digits;

	tot = 0;
	if (nbr < 0)
	{
		tot += ft_putchar('-');
		nbr = nbr * -1;
	}
	digits = ft_get_digits(nbr);
	while (digits != 0)
	{
		tot += ft_putchar((nbr / digits) + '0');
		nbr = nbr % digits;
		digits = digits / 10;
	}
	return (tot);
}

int	ft_putnbr_uns(unsigned int nbr)
{
	int	tot;
	int	digits;

	tot = 0;
	digits = ft_get_digits(nbr);
	while (digits != 0)
	{
		tot += ft_putchar((nbr / digits) + '0');
		nbr = nbr % digits;
		digits = digits / 10;
	}
	return (tot);
}
