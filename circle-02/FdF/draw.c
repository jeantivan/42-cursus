/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:36:35 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/19 00:42:51 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void drawline(mlx_image_t* image, t_point p1, t_point p2)
{
	uint32_t x1 = p1.x_iso;
	uint32_t x2 = p2.x_iso;
	uint32_t y1 = p1.y_iso;
	uint32_t y2 = p2.y_iso;

	uint32_t dx = abs(x2 - x1);
	uint32_t dy = abs(y2 - y1);
	bool steep = dy > dx;

	if (steep)
	{
		uint32_t temp = x1;
		x1 = y1;
		y1 = temp;
		temp = x2;
		x2 = y2;
		y2 = temp;
	}
	if (x1 > x2)
	{
		uint32_t temp = x1;
		x1 = x2;
		x2 = temp;

		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	uint32_t error = dx / 2;
	bool ystep = (y1 < y2) ? 1 : -1;
	uint32_t y = y1;
	uint32_t x = x1;

	while (x <= x2)
	{
		if (x < image->width && y < image->height)
		{
			if (steep)
			{
				mlx_put_pixel(image, y, x, 0x000000);
			}else{
				mlx_put_pixel(image, x, y, 0x000);
			}
		}
		printf("x: %u y: %u\n", x, y);
		error -= dy;
		if (error < 0)
		{
			y += ystep;
			error += dx;
		}
		x++;
	}
}

