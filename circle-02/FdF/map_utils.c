/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:16:34 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/04 19:00:11 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_dimensions(char *path_to_file, t_map *map)
{
	int		lines;
	int		col_len;
	char	*row;
	char	**col;
	int		fd;

	fd = open(path_to_file, O_RDONLY);
	lines = 0;
	row = get_row(fd);
	col = ft_split(row, ' ');
	if (!col)
		col_len = -1;
	else
		col_len = ft_arr_len(col);
	ft_free_split(col);
	while (row)
	{
		lines++;
		ft_safe_free((void **)&row);
		row = get_row(fd);
	}
	map->cols = col_len;
	map->rows = lines;
}

void	parse_map(t_map *map, t_point *points)
{
	size_t	len;
	float	center[2];

	len = map->cols * map->rows;
	project_points(map->points, points, len, map->ang);
	ortho_projection(points, len);
	scale_points(points, len, map->scale);
	get_center_coords(points, len, center);
	translate_points(points, len, map->center, center);
}

void	prepare_map(t_map *map, t_point *projection, size_t len, bool fit)
{
	len = map->cols * map->rows;
	copy_points(projection, map->points, len);
	parse_map(map, projection);
	if (fit)
	{
		map->scale = 1;
		while (points_fit(projection, len))
		{
			copy_points(projection, map->points, len);
			parse_map(map, projection);
			map->scale += 5;
		}
	}
}
