/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:34:55 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/19 01:09:55 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_show_point(t_point point)
{
	printf("{ x: %.2f, y: %.2f, z: %.2f, color: %u }\n", \
	point.coords[X], point.coords[Y], point.coords[Z], point.color);
}

bool	points_fit(t_point *points, size_t len)
{
	size_t	i;
	int		x;
	int		y;

	i = 0;
	while (i < len)
	{
		x = round(points[i].coords[X]);
		y = round(points[i].coords[Y]);
		if (x < MARGIN || x > WIN_W - MARGIN)
			return (false);
		if (y < MARGIN || y > WIN_H - MARGIN)
			return (false);
		i++;
	}
	return (true);
}

void	copy_points(t_point *dst, t_point *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
