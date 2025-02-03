/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:39:40 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/03 16:44:23 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_center_coords(t_point *points, size_t len, float center[2])
{
	float	min[2];
	float	max[2];
	size_t	i;

	i = 0;
	min[X] = points[i].coords[X];
	max[X] = points[i].coords[X];
	min[Y] = points[i].coords[Y];
	max[Y] = points[i].coords[Y];
	while (i < len)
	{
		if (points[i].coords[X] < min[X])
			min[X] = points[i].coords[X];
		if (points[i].coords[X] > max[X])
			max[X] = points[i].coords[X];
		if (points[i].coords[Y] < min[Y])
			min[Y] = points[i].coords[Y];
		if (points[i].coords[Y] > max[Y])
			max[Y] = points[i].coords[Y];
		i++;
	}
	center[X] = (min[X] + max[X]) / 2;
	center[Y] = (min[Y] + max[Y]) / 2;
}

void	ortho_projection(t_point *points, size_t len)
{
	size_t	i;
	float	matrix_proj[3][3];

	i = 0;
	matrix_init(matrix_proj);
	matrix_proj[0][0] = 1;
	matrix_proj[1][1] = 1;
	while (i < len)
	{
		points[i] = matmul(matrix_proj, points[i]);
		i++;
	}
}

void	scale_points(t_point *points, size_t len, float factor)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		points[i].coords[X] = (points[i].coords[X]) * factor;
		points[i].coords[Y] = (points[i].coords[Y]) * factor;
		i++;
	}
}

void	translate_points(t_point *points, size_t len, float c[2], float m[2])
{
	size_t	i;
	float	x_off;
	float	y_off;

	i = 0;
	x_off = c[X] - m[X];
	y_off = c[Y] - m[Y];
	while (i < len)
	{
		points[i].coords[X] += x_off;
		points[i].coords[Y] += y_off;
		i++;
	}
}

void	project_points(t_point *points, t_point *proj, size_t len, float ang[3])
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		proj[i] = rotate_x(points[i], ang[X]);
		proj[i] = rotate_y(proj[i], ang[Y]);
		proj[i] = rotate_z(proj[i], ang[Z]);
		i++;
	}
}
