/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:49:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/16 18:09:16 by jtivan-r         ###   ########.fr       */
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
	delta[X] = abs(p1.coords[X] - p0.coords[X]);
	delta[Y] = abs(p1.coords[Y] - p0.coords[Y]);
}

static void	plotLineLow(mlx_image_t *image, int p0[2], int p1[2], int delta[2])
{
	int	yi;
	int	D;
	int	y;

	yi = 1;
	if (delta[Y] < 0)
	{
		yi = -1;
		delta[Y] = -delta[Y];
	}
	D = (2 * delta[Y]) - delta[X];
	y = p0[Y];
	while (p0[X] < p1[X])
	{
		my_put_pixel(image, p0[X], y, 255);
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (delta[X] - delta[Y]));
		}
		else
			D = D + 2 * delta[Y];
		p0[X]++;
	}
}

static void	plotLineHigh(mlx_image_t *image, int p0[2], int p1[2], int delta[2])
{
	int	xi;
	int	D;
	int	x;

	xi = 1;
	if (delta[X] < 0)
	{
		xi = -1;
		delta[X] = -delta[X];
	}
	D = (2 * delta[X] - delta[Y]);
	x = p0[X];
	while (p0[Y] < p1[Y])
	{
		my_put_pixel(image, x, p0[Y], 255);
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (delta[X] - delta[Y]));
		}
		else
			D = D + 2 * delta[X];
		p0[Y]++;
	}
}

void	plotLine(mlx_image_t *image, t_point point0, t_point point1)
{
	int	p0[2];
	int	p1[2];
	int	delta[2];

	p0[X] = point0.coords[X];
	p0[Y] = point0.coords[Y];
	p1[X] = point1.coords[X];
	p1[Y] = point1.coords[Y];
	get_delta(delta, point0, point1);
	if (abs(p1[Y] - p0[Y]) < abs(p1[X] - p0[X]))
	{
		if (p0[X] > p1[X])
			plotLineLow(image, p1, p0, delta);
		else
			plotLineLow(image, p0, p1, delta);
	} else
	{
		if (p0[Y] > p1[Y])
			plotLineHigh(image, p1, p1, delta);
		else
			plotLineHigh(image, p0, p1, delta);
	}

}
