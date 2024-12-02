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

static int	ft_power(int nb, int power)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	if (power < 0)
		return (0);
	else if (power == 0 && nb == 0)
		return (1);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

static int	ft_n_digits(int n)
{
	int	digits;

	digits = 1;
	while (n / 10 != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static char	*ft_get_str_memory(int n)
{
	char	*str;
	size_t	size;

	size = ft_n_digits(n);
	if (n < 0)
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		size;
	long int	new_n;
	char		*str;
	int			i;

	new_n = n + 0;
	i = 0;
	size = ft_n_digits(n);
	str = ft_get_str_memory(n);
	if (!str)
		return (NULL);
	if (new_n < 0)
	{
		new_n *= -1;
		str[i++] = '-';
	}
	while (size != 0)
	{
		str[i++] = (char)((new_n / ft_power(10, --size)) + '0');
		new_n = new_n % ft_power(10, size);
	}
	str[i] = '\0';
	return (str);
}
