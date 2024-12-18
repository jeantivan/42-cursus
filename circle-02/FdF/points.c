/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:03:40 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/18 23:54:25 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_show_point(t_point point)
{
	printf("{ x: %i, y: %i, z: %i, x_iso: %.2f y_iso: %.2f color: %i }\n", \
	point.x, point.y, point.z, point.x_iso, point.y_iso ,point.color);
}

static void	get_point(char *el, int x, int y, t_point *point)
{
	char	**pieces;
	float	sin30 = 1.0 / 2.0;
	float	cos30 = sqrt(3.0) / 2.0;

	if (!valid_point(el))
	{
		point = NULL;
		return ;
	}
	pieces = ft_split(el, ',');
	if (!pieces)
	{
		point = NULL;
		return ;
	}
	if (ft_arr_len(pieces) >= 2)
		point->color = get_color(pieces[1]);
	else
		point->color = get_color(DEFAULT_COLOR);
	point->x = x;
	point->y = y;
	point->z = ft_atoi(pieces[0]);
	point->x_iso = (x * cos30) - (y * cos30);
	point->y_iso = (-point->z + (x * sin30)) +(y * sin30);
	ft_free_split(pieces);
}

static bool	row_to_points(char *row, int y, t_point *points, int cols)
{
	t_point	*point;
	char	**col;
	int		x;

	x = 0;
	col = ft_split(row, ' ');
	if (!valid_col(col, cols))
		return (false);
	while (col[x])
	{
		point = &points[(cols * y) + x];
		get_point(col[x], x, y, point);
		if (!point)
		{
			ft_free_split(col);
			return (false);
		}
		x++;
	}
	ft_free_split(col);
	return (true);
}

void	get_points(int fd, t_map *map)
{
	char		*row;
	int			line;

	line = 0;
	row = get_row(fd);
	while (row)
	{
		if (!row_to_points(row, line++, map->points, map->cols))
		{
			ft_safe_free((void **)&map->points);
			ft_safe_free((void **)&row);
			return ;
		}
		ft_safe_free((void **)&row);
		row = get_row(fd);
	}
}
