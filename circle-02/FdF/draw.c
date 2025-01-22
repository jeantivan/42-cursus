/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:36:35 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/22 20:21:35 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if (x > 0 && x < WIN_W && y > 0 && y < WIN_H)
	{
		mlx_put_pixel(image, x, y, color);
	}
}

void	draw_dot(mlx_image_t *image, t_point p)
{
	put_pixel(image, round(p.coords[X]), round(p.coords[Y]), p.color);
	put_pixel(image, round(p.coords[X] - 1), round(p.coords[Y]), p.color);
	put_pixel(image, round(p.coords[X] + 1), round(p.coords[Y]), p.color);
	put_pixel(image, round(p.coords[X]), round(p.coords[Y] - 1), p.color);
	put_pixel(image, round(p.coords[X]), round(p.coords[Y] + 1), p.color);
}

void	draw_points(mlx_image_t *image, t_point *points, size_t len)
{
	t_point	point;
	size_t	i;

	i = 0;
	while (i < len)
	{
		point = points[i];
		if (i == 0)
		{
			ft_show_point(point);
		}
		draw_dot(image, point);
		i++;
	}
}

void	join_points(mlx_image_t	*image, t_map *map)
{
	int			x;
	int			y;
	t_neighbors	neighbors;
	t_point		curr;

	printf("Uniendo lineas\n");
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			curr = map->points[get_index(x, y, map->cols)];
			neighbors = get_neighbors(x, y, map);
			if (neighbors.has_right)
				dda(image, curr, *neighbors.right);
			if (neighbors.has_bottom)
				dda(image, curr, *neighbors.bottom);
			x++;
		}
		y++;
	}
}
