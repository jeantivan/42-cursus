/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:43:33 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/21 19:13:10 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	tot;
	int	digits;

	tot = 0;
	digits = 1000000000;
	if (nbr < 0)
	{
		tot += ft_putchar('-');
		nbr = nbr * -1;
	}
	while (nbr / digits == 0)
		digits = digits / 10;
	while (digits != 0)
	{
		tot += ft_putchar((nbr / digits) + '0');
		nbr = nbr % digits;
		digits = digits / 10;
	}
	return (tot);
}
