/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:37:50 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/03 16:41:34 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_index(int x, int y, int cols)
{
	return ((cols * y) + x);
}

int	is_valid_point(int x, int y, int rows, int cols)
{
	return (x >= 0 && x < cols && y >= 0 && y < rows);
}

t_neighbors	get_neighbors(int x, int y, t_map *map, t_point *projection)
{
	t_neighbors	neighbors;

	neighbors.right = NULL;
	neighbors.bottom = NULL;
	neighbors.has_right = false;
	neighbors.has_bottom = false;
	if (is_valid_point(x + 1, y, map->rows, map->cols))
	{
		neighbors.right = &projection[get_index(x + 1, y, map->cols)];
		neighbors.has_right = true;
	}
	if (is_valid_point(x, y + 1, map->rows, map->cols))
	{
		neighbors.bottom = &projection[get_index(x, y + 1, map->cols)];
		neighbors.has_bottom = true;
	}
	return (neighbors);
}
