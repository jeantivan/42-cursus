/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:45:39 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/19 01:10:33 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_delta(int delta[2], t_point p0, t_point p1)
{
	delta[X] = p1.coords[X] - p0.coords[X];
	delta[Y] = p1.coords[Y] - p0.coords[Y];
}
// TODO: Implentar el antialiasing
static void	dda_aux(mlx_image_t *image, t_point p0, int steps, float inc[2])
{
	float	x;
	float	y;
	int		i;

	x = p0.coords[X];
	y = p0.coords[Y];
	put_pixel(image, round(x), round(y), p0.color);
	i = 0;
	while (i < steps)
	{
		x += inc[X];
		y += inc[Y];
		put_pixel(image, round(x), round(y), p0.color);
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
