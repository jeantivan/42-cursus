/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:36:35 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/23 14:02:12 by jtivan-r         ###   ########.fr       */
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

void	draw_points(t_state *state, t_point *points, size_t len)
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
		draw_dot(state->image, point);
		i++;
	}
}

void	join_points(t_state *state, t_point *proyection)
{
	int			i;
	int			j;
	t_neighbors	nei;
	t_point		curr;

	j = 0;
	while (j < state->map->rows)
	{
		i = 0;
		while (i < state->map->cols)
		{
			curr = proyection[get_index(i, j, state->map->cols)];
			nei = get_neighbors(i, j, state->map, proyection);
			if (nei.has_right)
				dda(state->image, curr, *nei.right);
			if (nei.has_bottom)
				dda(state->image, curr, *nei.bottom);
			i++;
		}
		j++;
	}

}
