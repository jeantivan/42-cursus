/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:45:39 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/16 19:06:02 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

static void	my_put_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if (x > MARGIN && x < WIN_W - MARGIN && y > MARGIN && y < WIN_H - MARGIN)
		mlx_put_pixel(image, x, y, color);
}
static void	get_delta(int delta[2], t_point p0, t_point p1)
{
	delta[X] = fabs(p1.coords[X] - p0.coords[X]);
	delta[Y] = fabs(p1.coords[Y] - p0.coords[Y]);
}

void DDA(mlx_image_t *image, t_point point0, t_point point1)
{
	int	delta[2];
	int	steps;
	int x_inc;
	int y_inc;

	get_delta(delta, point0, point1);
	if (delta[X] > delta[Y])
		steps = delta[X];
	else
		steps = delta[Y];
	x_inc = (float)(point1.coords[X] - point0.coords[X]) / steps;
	y_inc = (float)(point1.coords[Y] - point0.coords[Y])  / steps;

	float x = point0.coords[X];
	float y = point0.coords[Y];
	my_put_pixel(image, round(x), round(y), 255);
	int i = 0;
	while (i < steps)
	{
		x += x_inc;
		y += y_inc;
		my_put_pixel(image, round(x), round(y), 255);
		i++;
	}
}
