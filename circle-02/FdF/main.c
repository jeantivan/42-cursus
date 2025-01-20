/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/20 16:43:23 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

void	draw_map(mlx_image_t *image, t_map *map)
{
	prepare_map(map, true);
	draw_points(image, map->points, map->cols * map->rows);
	join_points(image, map);
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

void	render(t_map *map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIN_W, WIN_H, "FdF - jtivan-r", true);
	if (!mlx)
		ft_error("while rendering map");
	img = mlx_new_image(mlx, WIN_W, WIN_H);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	draw_map(img, map);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

t_map	*init_map(t_map *map, char *file)
{
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

int	main(int ac, char **av)
{
	char	*file;
	int		fd;
	t_map	*map;

	if (ac != 2)
		return (1);
	file = av[1];
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Bad file");
	close(fd);
	map = init_map(map, file);
	if (!map)
		ft_error("While parsing the map");
	printf("WIN_W: %d WIN_H: %d\n\n", WIN_W, WIN_H);
	render(map);
	ft_safe_free((void **)&map->points);
	ft_safe_free((void **)&map);
	return (0);
}
