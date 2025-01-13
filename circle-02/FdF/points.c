/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:03:40 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/13 15:21:57 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_show_point(t_point point)
{
	printf("{ x: %.2f, y: %.2f, z: %.2f, color: %u }\n", \
	point.coords[X], point.coords[Y], point.coords[Z], point.color);
}

static void	get_point(char *el, int x, int y, t_point *point)
{
	char	**pieces;

	if (!valid_point(el))
	{
		point = NULL;
		return ;
	}
	pieces = ft_split(el, ',');
	// if (ft_strchr(el, ',') != 0)
	// 	point->color = get_color(pieces[1]);
	// else
	point->color = get_color(DEFAULT_COLOR);
	point->coords[X] = x;
	point->coords[Y] = y;
	point->coords[Z] = ft_atoi(pieces[0]);
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
