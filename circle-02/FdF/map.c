/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:50:59 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/04 21:47:42 by jtivan-r         ###   ########.fr       */
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

t_map	*create_map(char *path_to_file)
{
	t_map	*map;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	get_map_dimensions(path_to_file, map);
	if (map->cols * map->rows <= 0)
		return (ft_safe_free((void **)&map));
	fd = open(path_to_file, O_RDONLY);
	if (fd < 0)
		return (ft_safe_free((void **)&map));
	map->points = (t_point *)malloc((map->rows * map->cols) * sizeof(t_point));
	if (!map->points)
		return (ft_safe_free((void **)&map));
	get_points(fd, map);
	close(fd);
	if (!map->points)
	{
		printf("----- error with points \n");
		return (ft_safe_free((void **)&map));
	}
	return (map);
}
