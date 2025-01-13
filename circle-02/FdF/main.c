/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/13 18:08:13 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

void	get_center_coords(t_map *map)
{
	float	x_min;
	float	x_max;
	float	y_min;
	float	y_max;
	int		i;

	i = 0;
	x_min = map->points[i].coords[X];
	x_max = map->points[i].coords[X];
	y_min = map->points[i].coords[Y];
	y_max = map->points[i].coords[Y];
	while (i < map->cols * map->rows)
	{
		if (map->points[i].coords[X] < x_min)
			x_min = map->points[i].coords[X];
		if (map->points[i].coords[X] > x_max)
			x_max = map->points[i].coords[X];
		if (map->points[i].coords[Y] < y_min)
			y_min = map->points[i].coords[X];
		if (map->points[i].coords[Y] > y_max)
			y_max = map->points[i].coords[X];
		i++;
	}
	map->x_center = (x_min + x_max) / 2;
	map->y_center = (y_min + y_max) / 2;
	map->x_offset = (WIDTH / 2) - map->x_center;
	map->y_offset = (HEIGHT / 2) - map->y_center;
}

void	proyect_points(t_map *map)
{
	int	i;

	i = 0;
	while(i < map->cols * map->rows)
	{
		map->points[i] = rotate_x(map->points[i], map->ang[X]);
		map->points[i] = rotate_y(map->points[i], map->ang[Y]);
		map->points[i] = rotate_z(map->points[i], map->ang[Z]);
		i++;
	}
}

bool	points_fit(t_map *map)
{
	int	i;
	int x;
	int	y;

	i = 0;
	while (i < map->rows * map->cols)
	{
		x = map->points[i].coords[X];
		y = map->points[i].coords[Y];
		x = (map->x_center + (x - map->x_center) * map->scale) + map->x_offset;
		y = (map->y_center + (y - map->y_center) * map->scale) + map->y_offset;
		if ( x < 10 || y < 10 || x > WIDTH - 10 || y > HEIGHT - 10)
			return (false);
		i++;
	}
	return (true);
}

void	scale_points(t_map *map)
{
	int		i;
	float	factor;

	i = 0;
	factor = map->scale;
	while (i < map->cols * map->rows)
	{
		map->points[i].coords[X] = map->x_center + \
		(map->points[i].coords[X] - map->x_center) * factor;
		map->points[i].coords[Y] = map->y_center + \
		(map->points[i].coords[Y] - map->y_center) * factor;
		map->points[i].coords[Z] = map->points[i].coords[Z];
		i++;
	}
}

void	translate_points(t_map *map)
{
	int	i;

	i = 0;
	while(i < map->cols * map->rows)
	{
		map->points[i].coords[X] += map->x_offset;
		map->points[i].coords[Y] += map->y_offset;
		i++;
	}
}

void	fit_map(t_map *map)
{
	int	i;

	i = 0;
	while (!points_fit(map))
	{
		map->scale -= 0.5;
		if (map->scale == 1)
			break ;
	}
}

void	draw_points(mlx_image_t *image, t_map *map)
{
	t_point	point;
	int		i;

	i = 0;
	while (i < map->cols * map->rows)
	{
		point = map->points[i];
		ft_show_point(point);
		if (point.coords[X] > 0 && point.coords[X] < WIDTH && \
		point.coords[Y] > 0 && point.coords[Y] < HEIGHT)
		{
			mlx_put_pixel(image, point.coords[X], point.coords[Y], 0x000000FA);
		}
		i++;
	}
}

void	draw_map(mlx_image_t* image, t_map *map)
{
	// int		i;
	t_point	c_point;

	printf("\nPuntos\n\n");
	// i = 0;
	draw_points(image, map);
	printf("\n ----------- ---------- \n");
	join_points(image, map);
}

void	prepare_map(t_map *map)
{
	proyect_points(map);
	fit_map(map);
	scale_points(map);
	get_center_coords(map);
	translate_points(map);
}

void	render(t_map *map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
		ft_error("while rendering map");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	prepare_map(map);
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
		map->scale = 100;
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
	t_meta	*meta;

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
	render(map);
	ft_safe_free((void **)&map->points);
	ft_safe_free((void **)&map);
	return (0);
}
