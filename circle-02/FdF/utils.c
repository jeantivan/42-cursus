/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:09:46 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/18 17:16:30 by jtivan-r         ###   ########.fr       */
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

static void	get_rgba(char *color, uint8_t *r, uint8_t *g, uint8_t *b, uint8_t *a)
{
	size_t	len;
	char	*r_s;
	char	*g_s;
	char	*b_s;
	char	*a_s;

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

static void	get_rgb(char *color, uint8_t *r_int, uint8_t *g_int, uint8_t *b_int)
{
	size_t	len;
	char	*r;
	char	*g;
	char	*b;
	int 	factor;

	len = ft_strlen(color);
	if (len == 6)
	{
		r = ft_substr(color, 0, 2);
		g = ft_substr(color, 2, 2);
		b = ft_substr(color, 4, 2);
		factor = 1;
	}
	else if (len == 3)
	{
		r = ft_substr(color, 0, 1);
		g = ft_substr(color, 1, 1);
		b = ft_substr(color, 2, 1);
		factor = 17;
	}
	*r_int = ft_atoi_base(r, HEX_LOWER) * factor;
	*g_int = ft_atoi_base(g, HEX_LOWER) * factor;
	*b_int = ft_atoi_base(b, HEX_LOWER) * factor;
}

// uint32_t	get_color(char *color)
// {
// 	size_t	len;
// 	uint8_t	r;
// 	uint8_t	g;
// 	uint8_t	b;
// 	uint8_t	a;

// 	if (!valid_hex(color))
// 		return (0x000000FF);
// 	color += 2;
// 	r = 0;
// 	g = 0;
// 	b = 0;
// 	a = 255;
// 	len = ft_strlen(color);
// 	// AABBCCDD ABCD
// 	// AABBCC ABC
// 	if (len == 8 || len == 4)
// 		get_rgba(color, &r, &g, &b, &a);
// 	else if (len == 6 || len == 3)
// 		get_rgb(color, &r, &g, &b);
// 	else
// 		return (0x000000FF);
// 	printf("after \n r: %u g: %u b: %u a: %u\n", r, g, b, a);
// 	printf("all: %u\n", ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | (uint32_t)a);
// 	return (((uint32_t)r << 24) | ((uint32_t)g << 16) \
// 	| ((uint32_t)b << 8) | (uint32_t)a);
// }
