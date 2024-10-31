/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:45:28 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/25 17:45:29 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			digits;
	long int	temp_nb;
	char		c_w;

	temp_nb = 0 + n;
	digits = 1000000000;
	if (temp_nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (temp_nb < 0)
	{
		write(fd, "-", 1);
		temp_nb = -1 * temp_nb;
	}
	while (temp_nb / digits == 0)
		digits = digits / 10;
	while (digits != 0)
	{
		c_w = (temp_nb / digits) + '0';
		write(fd, &c_w, 1);
		temp_nb = temp_nb % digits;
		digits = digits / 10;
	}
}
