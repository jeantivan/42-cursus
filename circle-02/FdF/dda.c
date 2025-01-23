/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:45:39 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/23 19:26:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_delta(int delta[2], t_point p0, t_point p1)
{
	delta[X] = p1.coords[X] - p0.coords[X];
	delta[Y] = p1.coords[Y] - p0.coords[Y];
}

void	put_pixel2(mlx_image_t *image, float p[2], uint32_t color)
{
	uint32_t	alpha;
	int			xi;
	int			yi;
	float		xFrac;
	float		yFrac;

	xi = (int)p[X];
	yi = (int)p[Y];
	xFrac = p[X] - xi;
	yFrac = p[Y] - yi;
	alpha = (color & 0xFF);
	if (p[X] > 0 && p[X] < WIN_W && p[Y] > 0 && p[Y] < WIN_H)
	{
		mlx_put_pixel(image, xi, yi, color | (uint32_t)(alpha * (1.0f - fmax(xFrac, yFrac))));
		if (xFrac > yFrac)
			mlx_put_pixel(image, xi + 1, yi, color | (uint32_t)(alpha * (fmax(xFrac, yFrac))));
		else
			mlx_put_pixel(image, xi, yi + 1, color | (uint32_t)(alpha * (fmax(xFrac, yFrac))));
	}
}

// TODO: Implentar el antialiasing
static void	dda_aux(mlx_image_t *image, t_point p0, int steps, float inc[2])
{
	float	p[2];
	int		i;
	int		xi;
	int		yi;

	p[X] = p0.coords[X];
	p[Y] = p0.coords[Y];
	//put_pixel(image, round(x), round(y), p0.color);
	i = 0;
	while (i < steps)
	{

		put_pixel2(image, p, p0.color);
		p[X] += inc[X];
		p[Y] += inc[Y];
		i++;
	}
}

void	dda(mlx_image_t *image, t_point point0, t_point point1)
{
	int		delta[2];
	int		steps;
	float	increment[2];

	get_delta(delta, point0, point1);
	if (abs(delta[X]) > abs(delta[Y]))
		steps = abs(delta[X]);
	else
		steps = abs(delta[Y]);
	increment[X] = delta[X] / (float)steps;
	increment[Y] = delta[Y] / (float)steps;
	dda_aux(image, point0, steps, increment);
}
