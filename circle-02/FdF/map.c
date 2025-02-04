/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:50:59 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/04 18:59:03 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*create_map(char *path_to_file)
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
		return (ft_safe_free((void **)&map));
	return (map);
}

t_map	*init_map(char *file)
{
	t_map	*map;

	map = create_map(file);
	if (map)
	{
		map->scale = 1;
		map->center[X] = WIN_W / 2;
		map->center[Y] = WIN_H / 2;
		map->ang[X] = 30;
		map->ang[Y] = 330;
		map->ang[Z] = 30;
	}
	return (map);
}

void	clean_map(t_map *map)
{
	ft_safe_free((void **)&map->points);
	ft_safe_free((void **)&map);
}

void	draw_map(t_state *state, bool fit)
{
	size_t	len;
	size_t	size;
	t_point	*projection;

	len = state->map->cols * state->map->rows;
	projection = (t_point *)malloc((len) * sizeof(t_point));
	size = state->image->width * state->image->height * sizeof(int32_t);
	ft_memset(state->image->pixels, 255, size);
	prepare_map(state->map, projection, len, fit);
	if (state->dots)
		draw_points(state, projection, len);
	if (state->lines)
		join_points(state, projection);
	ft_safe_free((void **)&projection);
}
