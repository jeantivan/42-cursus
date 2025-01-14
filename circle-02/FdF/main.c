/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/14 19:24:54 by jtivan-r         ###   ########.fr       */
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
	map->x_offset = (WIN_W / 2) - map->x_center;
	map->y_offset = (WIN_H / 2) - map->y_center;
}

void	proyect_points(t_map *map)
{
	int		i;


	i = 0;
	while(i < map->cols * map->rows)
	{
		map->points[i] = rotate_x(map->points[i], map->ang[X]);
		map->points[i] = rotate_y(map->points[i], map->ang[Y]);
		map->points[i] = rotate_z(map->points[i], map->ang[Z]);
		i++;
	}
}

void	ortho_proyection(t_map *map)
{
	int	i;
	float	matrix_proy[3][3];

	i = 0;
	matrix_init(matrix_proy);
	matrix_proy[0][0] = 1;
	matrix_proy[1][1] = 1;
	while (i < map->cols * map->rows)
	{
		map->points[i] = matmul(matrix_proy, map->points[i]);
		i++;
	}
}

bool	points_fit(t_point *points, size_t len)
{
	size_t	i;
	int		x;
	int		y;

	i = 0;
	while (i < len)
	{
		x = points[i].coords[X];
		y = points[i].coords[Y];
		if ( x < MARGIN ||x > WIN_W - MARGIN)
			return (false);
		if (y < MARGIN || y > WIN_H - MARGIN)
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
		map->points[i].coords[X] = map->points[i].coords[X] * factor;
		map->points[i].coords[Y] = map->points[i].coords[Y] * factor;
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
		map->points[i].coords[X] += map->center[X];
		map->points[i].coords[Y] += map->center[Y];
		i++;
	}
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
void	fit_map(t_map *map)
{
	int	i;
	t_point *points;

	i = 0;
	points = (t_point *)malloc(sizeof(t_point) * map->cols * map->rows);
	copy_points(points, map->points, map->rows * map->cols);
	while (points_fit(points, map->cols * map->rows))
	{

		map->scale += 0.5;
	}
}

void	draw_points(mlx_image_t *image, t_point *points, size_t len)
{
	t_point	point;
	size_t	i;

	i = 0;
	while (i < len)
	{
		point = points[i];
		if (point.coords[X] > 0 && point.coords[X] < WIN_W && \
		point.coords[Y] > 0 && point.coords[Y] < WIN_H)
		{
			mlx_put_pixel(image, point.coords[X], point.coords[Y], 0x000000FA);
			mlx_put_pixel(image, point.coords[X] - 1, point.coords[Y], 0x000000FA);
			mlx_put_pixel(image, point.coords[X] + 1, point.coords[Y], 0x000000FA);
			mlx_put_pixel(image, point.coords[X], point.coords[Y] - 1, 0x000000FA);
			mlx_put_pixel(image, point.coords[X], point.coords[Y] + 1, 0x000000FA);
		}
		i++;
	}
}

void	mark_center(mlx_image_t *image)
{
	float	center_x;
	float	center_y;

	center_x = image->width / 2;
	center_y = image->height / 2;

	mlx_put_pixel(image, center_x, center_y, 0xFF0000FF);

	/* Laterales */
	mlx_put_pixel(image, center_x - 1 , center_y, 0xFF0000FF);
	mlx_put_pixel(image, center_x + 1, center_y, 0xFF0000FF);

	/* Superiores */
	mlx_put_pixel(image, center_x, center_y - 1, 0xFF0000FF);
	mlx_put_pixel(image, center_x, center_y + 1, 0xFF0000FF);

	/* Esquina UL*/
	mlx_put_pixel(image, center_x - 1, center_y - 1, 0xFF0000FF);

	/* Esquina UR*/
	mlx_put_pixel(image, center_x + 1, center_y - 1, 0xFF0000FF);

	/* Esquina DL */
	mlx_put_pixel(image, center_x - 1, center_y + 1, 0xFF0000FF);

	/* Esquina DR*/
	mlx_put_pixel(image, center_x + 1, center_y + 1, 0xFF0000FF);
}

void	draw_map(mlx_image_t *image, t_map *map)
{
	mark_center(image);
	//draw_points(image, map);
}

void	prepare_map(t_map *map, bool fit)
{
	int i;

	proyect_points(map);
	ortho_proyection(map);
	get_center_coords(map);
	if (fit)
		fit_map(map);
}

void	render(t_map *map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIN_W, WIN_H, "FdF", true);
	if (!mlx)
		ft_error("while rendering map");
	img = mlx_new_image(mlx, WIN_W, WIN_H);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	prepare_map(map, true);
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
		map->center.coords[X] = WIN_W / 2;
		map->center.coords[Y] = WIN_H / 2;
		map->center.coords[Z] = 0;
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
	printf("WIN_W: %d WIN_H: %d\n\n", WIN_W, WIN_H);
	render(map);
	ft_safe_free((void **)&map->points);
	ft_safe_free((void **)&map);
	return (0);
}
