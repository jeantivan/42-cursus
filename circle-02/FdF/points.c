/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:03:40 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/12 18:43:26 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point *get_point(char *el, int x, int y)
{
	char	**pieces;
	t_point	*point;

	pieces = ft_split(el, ',');
	if (!pieces)
		return (NULL);
	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	if (ft_arr_length(pieces) >= 2)
		point->color = get_color(pieces[1]);
	else
		point->color = get_color(DEFAULT_COLOR);
	point->x = x;
	point->y = y;
	point->z = ft_atoi(pieces[0]);
	ft_free_split(pieces);
	return (point);
}

bool row_to_points(char *row, int x, t_point **points)
{
	t_point	*point;
	char	**col;
	int		y;

	y = 0;
	col = ft_split(row, ' ');
	while (col[y])
	{
		point = get_point(col[y], x, y);
		if (!point)
			return (false);
		points[x + y] = point;
		y++;
	}
	return (true);
}

void *ft_free_points(t_point **points)
{
	int	i;

	i = 0;
	if (!points)
		return (NULL);
	while (points[i])
	{
		ft_safe_free((void **)&points[i]);
		i++;
	}
	ft_safe_free((void **)points);
	return (NULL);
}

t_point **get_points(const char *path_to_file, int dimensions)
{
	t_point		**points;
	int			fd;
	char		*row;
	int			line;

	fd = open(path_to_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	points = (t_point **)malloc((dimensions + 1) * sizeof(t_point));
	if (points)
		return (NULL);
	line = 0;
	row = get_row(fd);
	while (row)
	{
		if (!row_to_points(row, line, points))
		{
			close(fd);
			return (ft_free_points(points));
		}
		line++;
		ft_safe_free((void **)&row);
		row = get_row(fd);
	}
	close(fd);
	return (points);
}
