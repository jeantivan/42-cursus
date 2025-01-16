/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:36:35 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/16 18:14:01 by jtivan-r         ###   ########.fr       */
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


void	my_put_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if (x > MARGIN && x < WIN_W - MARGIN && y > MARGIN && y < WIN_H - MARGIN)
		mlx_put_pixel(image, x, y, color);
}

void	get_delta(int delta[2], t_point p0, t_point p1)
{
	delta[X] = abs(p1.coords[X] - p0.coords[X]);
	delta[Y] = abs(p1.coords[Y] - p0.coords[Y]);
}

void	get_steep(int steep[2], t_point p0, t_point p1)
{
	if (p0.coords[X] < p1.coords[X])
		steep[X] = 1;
	else
		steep[X] = -1;
	if (p0.coords[Y] < p1.coords[Y])
		steep[Y] = 1;
	else
		steep[Y] = -1;
}

void drawline(mlx_image_t* image, t_point p0, t_point p1, uint32_t color)
{
	int		delta[2];
	int		steep[2];
	int		err;
	double	e2;

	get_delta(delta, p0, p1);
	get_steep(steep, p0, p1);
	err = delta[X] - delta[Y];
	while (1)
	{
		my_put_pixel(image, p0.coords[X], p0.coords[Y], color);
		if (p0.coords[X] == p1.coords[X] && p0.coords[Y] == p0.coords[Y])
			break ;
		e2 = 2 * err;
		if (e2 > -delta[Y])
		{
			err -= delta[Y];
			p0.coords[X] += steep[X];
		}
		if (e2 < delta[X])
		{
			err += delta[X];
			p0.coords[Y] += steep[Y];
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
				plotLine(image, *curr, *right);
				//drawline(image, *curr, *right, 255);
			}
			if (y + 1 < map->rows)
			{
				bottom = &map->points[(map->cols * (y + 1)) + x];
				plotLine(image, *curr, *bottom);
				//drawline(image, *curr, *bottom, 255);
			}
			x++;
		}
		y++;
	}
}
