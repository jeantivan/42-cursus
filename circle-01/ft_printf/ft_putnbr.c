/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:43:33 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/23 15:19:53 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_get_digits(unsigned int nbr)
{
	int	digits;

	digits = 1000000000;
	while (nbr / digits == 0)
		digits = digits / 10;
	return (digits);
}

static	int	ft_print_negative(long int *nbr)
{
	int	count;

	count = 0;
	if (*nbr < 0)
	{
		count = ft_putchar('-');
		if (count == -1)
			return (-1);
		*nbr = -(*nbr);
	}
	return (count);
}

int	ft_putnbr(int nbr)
{
	int			tot;
	int			digits;
	long int	temp_nbr;

	tot = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	temp_nbr = nbr + 0;
	tot += ft_print_negative(&temp_nbr);
	if (tot == -1)
		return (-1);
	digits = ft_get_digits(temp_nbr);
	while (digits != 0)
	{
		tot += ft_putchar((temp_nbr / digits) + '0');
		temp_nbr = temp_nbr % digits;
		digits = digits / 10;
	}
	return (tot);
}

int	ft_putnbr_uns(unsigned int nbr)
{
	int					tot;
	int					temp_counter;
	int					digits;
	unsigned long int	temp_nbr;

	tot = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	temp_nbr = nbr + 0;
	digits = ft_get_digits(temp_nbr);
	while (digits != 0)
	{
		temp_counter = ft_putchar((temp_nbr / digits) + '0');
		if (temp_counter == -1)
			return (-1);
		tot += temp_counter;
		temp_nbr = temp_nbr % digits;
		digits = digits / 10;
	}
	return (tot);
}
