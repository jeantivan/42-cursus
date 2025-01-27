/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:25:49 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/31 15:26:22 by jtivan-r         ###   ########.fr       */
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
	else if (format == 's')
		counter += ft_putstr(va_arg(args, char *));
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
	else if (format == '\0')
		counter = -1;
	return (counter);
}

static int	ft_is_valid_format(char format)
{
	if (format == 'c' || format == 'i' || format == 'd' || \
	format == 's' || format == '%' || format == 'u' || \
	format == 'p' || format == 'x' || format == 'X')
		return (1);
	return (0);
}

static int	ft_printf_exec(char const *s, va_list args)
{
	int	i;
	int	temp;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_is_valid_format(s[i + 1]))
		{
			temp = ft_handle_formater(s[i + 1], args);
			if (temp == -1)
				break ;
			counter += temp;
			i += 2;
			continue ;
		}
		else if (s[i] == '%' && s[i + 1] == '\0')
			return (-1);
		temp = ft_putchar(s[i]);
		counter += temp;
		i++;
	}
	return (counter);
}

int	ft_printf(char const *s, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, s);
	counter = ft_printf_exec(s, args);
	va_end(args);
	return (counter);
}
