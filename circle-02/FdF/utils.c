/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:09:46 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/13 16:55:55 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_arr_len(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

bool	valid_hex(char *el)
{
	int		i;
	size_t	len;

	len = ft_strlen(el);
	if (!el || el[0] != '0' || (el[1] != 'x' && el[1] != 'X'))
		return (false);
	if (len <= 3 || (len != 5 && len != 8 && len != 6 && len != 10))
		return (false);
	i = 2;
	while (el[i])
	{
		if (!(('0' <= el[i] && el[i] <= '9') || \
			('a' <= el[i] && el[i] <= 'f') || \
			('A' <= el[i] && el[i] <= 'F')))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	valid_num(char *el)
{
	int	i;

	i = 0;
	if (!el || el[i] == '\0')
		return (false);
	if ((el[i] == '-' || el[i] == '+') && el[i + 1] == '\0')
		return (false);
	if (el[i] == '-' || el[i] == '+')
		i++;
	while (el[i])
	{
		if (!ft_isdigit(el[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	get_rgba(char *color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a)
{
	size_t	len;

	len = ft_strlen(color);
	if (len == 8)
	{
		*r = ft_atoi_base(color, HEX_LOWER);
		*g = ft_atoi_base(color + 2, HEX_LOWER);
		*b = ft_atoi_base(color + 4, HEX_LOWER);
		*a = ft_atoi_base(color + 6, HEX_LOWER);
	}
	else if (len == 5)
	{
		*r = ft_atoi_base(color, HEX_LOWER) * 17;
		*g = ft_atoi_base(color + 1, HEX_LOWER) * 17;
		*b = ft_atoi_base(color + 2, HEX_LOWER) * 17;
		*a = ft_atoi_base(color + 3, HEX_LOWER) * 17;
	}
}

static void	get_rgb(char *color, uint8_t *r, uint8_t *g, uint8_t *b)
{
	size_t	len;

	len = ft_strlen(color);
	if (len == 6)
	{
		*r = ft_atoi_base(color, HEX_LOWER);
		*g = ft_atoi_base(color + 2, HEX_LOWER);
		*b = ft_atoi_base(color + 4, HEX_LOWER);
	}
	else if (len == 4)
	{
		*r = ft_atoi_base(color, HEX_LOWER) * 17;
		*g = ft_atoi_base(color + 1, HEX_LOWER) * 17;
		*b = ft_atoi_base(color + 2, HEX_LOWER) * 17;
	}
}

uint32_t	get_color(char *color)
{
	size_t	len;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	if (!valid_hex(color))
		return (0x000000FF);
	color += 2;
	r = 0;
	g = 0;
	b = 0;
	a = 255;
	len = ft_strlen(color);
	if (len == 8 || len == 5)
		get_rgba(color, &r, &g, &b, &a);
	else if (len == 6 || len == 4)
		get_rgb(color, &r, &g, &b);
	else
		return (0x000000FF);
	return (((uint32_t)r << 24) | ((uint32_t)g << 16) \
	| ((uint32_t)b << 8) | (uint32_t)a);
}
