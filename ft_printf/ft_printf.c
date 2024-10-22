/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:25:49 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 19:11:46 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_handle_formater(char format, va_list args)
{
	int	counter;

	counter = 0;
	if (format == '%')
		counter += ft_putchar('%');
	else if (format == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (format == 'i' || format == 'd')
		counter += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		counter += ft_putnbr_uns(va_arg(args, unsigned int));
	else if (format == 'p')
		counter += ft_putpointer(va_arg(args, void *));
	else if (format == 'x')
		counter += ft_puthex((unsigned int)va_arg(args, int), 0);
	else if (format == 'X')
		counter += ft_puthex((unsigned int)va_arg(args, int), 1);
	return (counter);
}

int	ft_printf(char const *s, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			counter += ft_handle_formater(s[i + 1], args);
			i += 2;
			continue ;
		}
		counter += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
