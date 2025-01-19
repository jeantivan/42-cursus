/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:06:27 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/19 00:57:25 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hex_to_int(char *hex)
{
	return (ft_atoi_base(hex, HEX_LOWER));
}

uint32_t	get_alpha(char *color, size_t len)
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

uint32_t	get_rgb(char *color, size_t len)
{
	uint32_t	rgb;
	int			i;
	char		*hex;

	rgb = 0;
	i = 0;
	hex = NULL;
	printf("color: %s, len: %zu\n", color, len);
	if (len == 8 || len == 6)
		while (i <= 4)
		{
			hex = ft_substr(color, i, 2);
			printf("hex %s bits: %i\n", hex, (24 - 8 * (i / 2)));
			rgb |= (uint32_t)hex_to_int(hex) << (24 - 8 * (i / 2));
			ft_safe_free((void **)&hex);
			i += 2;
		}
	else
		while (i < 3)
		{
			hex = ft_substr(color, i, 1);
			printf("hex %s bits: %i\n", hex, (24 - 8 * (i)));
			rgb |= (uint32_t)(hex_to_int(hex)) << (24 - 8 * i);
			ft_safe_free((void **)&hex);
			i++;
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
	rgb = get_rgb(color, len);
	// AABBCCDD ABCD
	if (len == 8 || len == 4)
		a = get_alpha(color, len);
	else
		a = 255;
	return ((uint32_t)(rgb | a));
}
