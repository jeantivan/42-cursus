/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:26:48 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/14 18:05:52 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_init(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_point	matmul(float matrix[3][3], t_point point)
{
	int		i;
	int		k;
	t_point	r;

	r = point;
	i = 0;
	while (i < 3)
	{
		r.coords[i] = 0;
		k = 0;
		while (k < 3)
		{
			r.coords[i] += matrix[i][k] * point.coords[k];
			k++;
		}
		i++;
	}
	r.color = point.color;
	return (r);
}

t_point	rotate_x(t_point point, float ang)
{
	float	rad;
	float	matrix_proy[3][3];
	t_point	r;

	rad = ang * M_PI / 180;
	matrix_init(matrix_proy);
	matrix_proy[0][0] = 1;
	matrix_proy[1][1] = cos(rad);
	matrix_proy[1][2] = -sin(rad);
	matrix_proy[2][1] = sin(rad);
	matrix_proy[2][2] = cos(rad);
	r = matmul(matrix_proy, point);
	return (r);
}

t_point	rotate_y(t_point point, float ang)
{
	float	rad;
	float	matrix_proy[3][3];
	t_point	r;

	rad = ang * M_PI / 180;
	matrix_init(matrix_proy);
	matrix_proy[0][0] = cos(rad);
	matrix_proy[0][2] = sin(rad);
	matrix_proy[1][1] = 1;
	matrix_proy[2][0] = -sin(rad);
	matrix_proy[2][2] = cos(rad);
	r = matmul(matrix_proy, point);
	return (r);
}

t_point	rotate_z(t_point point, float ang)
{
	float	rad;
	float	matrix_proy[3][3];
	t_point	r;

	rad = ang * M_PI / 180;
	matrix_init(matrix_proy);
	matrix_proy[0][0] = cos(rad);
	matrix_proy[0][1] = -sin(rad);
	matrix_proy[1][0] = sin(rad);
	matrix_proy[1][1] = cos(rad);
	matrix_proy[2][2] = 1;
	r = matmul(matrix_proy, point);
	return (r);
}
