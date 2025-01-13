/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:20:13 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/13 15:55:30 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_str_tolower(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		//write(1, &s[i], 1);
		s[i] = (char)ft_tolower(s[i]);
		i++;
	}
}

static int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(const char *s, char *base)
{
	int	result;
	int	sign;
	int	base_len;

	if (!validate_base(base))
		return (0);
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign = -1;
	}
	result = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	while (*s && is_in_base(ft_tolower(*s), base))
	{
		result = result * base_len + base_index(ft_tolower(*s), base);
		s++;
	}
	return (result * sign);
}
