/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:47:05 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/23 13:33:56 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	temp;

	i = 0;
	if (!s)
	{
		temp = write(1, "(null)", 6);
		if (temp != 6)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		temp = ft_putchar(s[i]);
		if (temp != 1)
			return (-1);
		i += temp;
	}
	return (i);
}
