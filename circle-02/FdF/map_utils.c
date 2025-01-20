/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:16:34 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/20 17:26:25 by jtivan-r         ###   ########.fr       */
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

void	prepare_map(t_map *map, bool fit)
{
	size_t	len;
	t_point	*points;
	float	center[2];

	len = map->cols * map->rows;
	points = (t_point *)malloc((len) * sizeof(t_point));
	copy_points(points, map->points, len);
	proyect_points(map->points, points, len, map->ang);
	ortho_proyection(points, len);
	scale_points(points, len, map->scale);
	get_center_coords(points, len, center);
	translate_points(points, len, center);
	while (points_fit(points, len))
	{
		copy_points(points, map->points, len);
		proyect_points(map->points, points, len, map->ang);
		ortho_proyection(points, len);
		scale_points(points, len, map->scale);
		get_center_coords(points, len, center);
		translate_points(points, len, center);
		map->scale += .2;
	}
	ft_safe_free((void **)&map->points);
	map->points = points;
}
