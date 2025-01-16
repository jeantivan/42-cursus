/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/16 02:49:45 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

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

void	ortho_proyection(t_point *points, size_t len)
{
	size_t	i;
	float	matrix_proy[3][3];

	i = 0;
	matrix_init(matrix_proy);
	matrix_proy[0][0] = 1;
	matrix_proy[1][1] = 1;
	while (i < len)
	{
		points[i] = matmul(matrix_proy, points[i]);
		i++;
	}
}

void	proyect_points(t_point *points, t_point *proyection,size_t len, float ang[3])
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		proyection[i] = rotate_x(points[i], ang[X]);
		proyection[i] = rotate_y(proyection[i], ang[Y]);
		proyection[i] = rotate_z(proyection[i], ang[Z]);
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

void	translate_points(t_point *points, size_t len, float move[2])
{
	size_t	i;
	float	x_off;
	float	y_off;

	i = 0;
	x_off = (WIN_W / 2) - move[X];
	y_off = (WIN_H / 2) - move[Y];
	while(i < len)
	{
		points[i].coords[X] += x_off;
		points[i].coords[Y] += y_off;
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

void	draw_points(mlx_image_t *image, t_point *points, size_t len)
{
	t_point	point;
	size_t	i;

	i = 0;
	while (i < len)
	{
		point = points[i];
		if (point.coords[X] > MARGIN && point.coords[X] < WIN_W - MARGIN && \
		point.coords[Y] > MARGIN && point.coords[Y] < WIN_H - MARGIN)
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

void	draw_map(mlx_image_t *image, t_map *map)
{
	draw_points(image, map->points, map->cols * map->rows);
	join_points(image, map);
}

void	show_points(t_point *points, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_show_point(points[i]);
		i++;
	}
}

void	prepare_map(t_map *map, bool fit)
{
	int		i;
	size_t	len;
	t_point	*points;
	float	center[2];
	//TODO: GESTION DE MEMORIA
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
		map->scale += .5;
	}
	map->points = points;
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
		map->center[X] = WIN_W / 2;
		map->center[Y] = WIN_H / 2;
		map->ang[X] = 30;
		map->ang[Y] = -30;
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
