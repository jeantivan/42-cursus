/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:06:27 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/21 16:29:30 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hex_to_int(char *hex)
{
	return (ft_atoi_base(hex, HEX_LOWER));
}

static uint32_t	get_alpha(char *color, size_t len)
{
	int			factor;
	char		*hex;
	uint32_t	alpha;

	if (len == 8)
	{
		hex = ft_substr(color, len - 2, 2);
		factor = 1;
	}
	else
	{
		hex = ft_substr(color, len - 1, 1);
		factor = 17;
	}
	alpha = (uint32_t)hex_to_int(hex) * factor;
	ft_safe_free((void **)&hex);
	return (alpha);
}

static uint32_t	get_rgb(char *color, int limit, int spacing)
{
	int			i;
	uint32_t	rgb;
	char		*hex;

	i = 0;
	hex = NULL;
	rgb = 0;
	while (i <= limit)
	{
		hex = ft_substr(color, i, spacing);
		rgb |= (uint32_t)hex_to_int(hex) << (24 - 8 * (i / spacing));
		ft_safe_free((void **)&hex);
		i += spacing;
	}
	return (rgb);
}

uint32_t	get_color(char *color)
{
	size_t		len;
	uint32_t	rgb;
	uint32_t	a;

	if (!valid_hex(color))
		return (0x00000000);
	color += 2;
	len = ft_strlen(color);
	if (len == 8 || len == 4)
	{
		rgb = get_rgb(color, 4, 2);
		a = get_alpha(color, len);
	}
	else
	{
		rgb = get_rgb(color, 2, 1);
		a = 255;
	}
	return ((uint32_t)(rgb | a));
}
