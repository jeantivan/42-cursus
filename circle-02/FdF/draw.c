/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:36:35 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/14 17:42:53 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_neighbors {
	int	right;      // Vecino derecho
	int	bottom;     // Vecino inferior
	int	has_right;  // 1 si tiene vecino derecho, 0 si no
	int	has_bottom; // 1 si tiene vecino inferior, 0 si no
} t_neighbors;

int	get_index(int x, int y, int cols)
{
	return ((cols * y) + x);
}

int is_valid_point(int x, int y, int rows, int cols)
{
	return (x >= 0 && x < cols && y >= 0 && y < rows);
}

// Función para obtener los vecinos de un punto
t_neighbors	get_neighbors(int x, int y, t_map *map) {
	t_neighbors neighbors;

	neighbors.right = -1;
	neighbors.bottom = -1;
	neighbors.has_right = 0;
	neighbors.has_bottom = 0;
	if (is_valid_point(x + 1, y, map->rows, map->cols)) {
		neighbors.right = get_index(x + 1, y, map->cols);
		neighbors.has_right = 1;
	}
	if (is_valid_point(x, y + 1, map->rows, map->cols)) {
		neighbors.bottom = get_index(x, y + 1, map->cols);
		neighbors.has_bottom = 1;
	}
	return neighbors;
}

void drawline(mlx_image_t* image, t_point p0, t_point p1, uint32_t color)
{
	int x0 = p0.coords[X];
	int y0 = p0.coords[Y];
	int x1 = p1.coords[X];
	int y1 = p1.coords[Y];
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;
	while (1)
	{
		if (x0 > 0 && x0 < WIN_W && y0 > 0 && y0 < WIN_H)
		{
			mlx_put_pixel(image, x0, y0, color);
		}
		if (x0 == x1 && y0 == y1)
			break ;
		double e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}

}

void	join_points(mlx_image_t	*image, t_map *map)
{
	int			x;
	int			y;
	int			curr_i;
	t_neighbors	neighbors;
	t_point		*curr;
	t_point		*bottom;
	t_point		*right;

	printf("\n Joining points \n");
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			curr_i = get_index(x, y, map->cols);
			neighbors = get_neighbors(x, y, map);
			curr = &map->points[curr_i];
			if (x + 1 < map->cols)
			{
				right = &map->points[(map->cols * y) + (x + 1)];
				drawline(image, *curr, *right, 255);
			}
			if ( y + 1 < map->rows)
			{
				bottom = &map->points[(map->cols * (y + 1)) + x];
				drawline(image, *curr, *bottom, 255);
			}
			x++;
		}
		y++;
	}
}
