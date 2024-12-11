/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:05:23 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/11 20:17:40 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static int get_color(char *color)
{
	char	*r_str;
	char	*g_str;
	char	*b_str;

	if (!val_hex(color))
		return (DEFAULT_COLOR);
	r_str = ft_substr(color, 2, 4);
	g_str = ft_substr(color, 4, 6);
	b_str = ft_substr(color, 6, 8);
	ft_printf("r = %s g = %s b = %s\n", r_str, g_str, b_str);
	ft_safe_free((void **)&r_str);
	ft_safe_free((void **)&g_str);
	ft_safe_free((void **)&b_str);
	return 0;
}

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
	point->x = x;
	point->y = y;
	point->z = ft_atoi(pieces[0]);
	ft_free_split(pieces);
	return (point);
}
static bool valid_col(char **col)
{
	int		i;
	char	**piece;

	if(!col)
		return (false);
	i = 0;
	while (col[i])
	{
		piece = ft_split(col[i], ',');
		if (!piece)
			return (false);
		if (!val_num(piece[0]) || (ft_arr_length(piece) == 2 && !val_hex(piece[1])))
		{
			ft_free_split(piece);
			return (false);
		}
		ft_free_split(piece);
		i++;
	}
	return (true);
}

static char	*get_row(int fd)
{
	char	*raw_row;
	char	*row;
	size_t	len;

	raw_row = get_next_line(fd);
	if (!raw_row)
		return (NULL);
	len = ft_strlen(raw_row);
	if (raw_row[len - 1] == '\n')
	{
		row = ft_substr(raw_row, 0, ft_strlen(raw_row) - 1);
		ft_safe_free((void **)&raw_row);
	}
	else
		row = raw_row;
	return (row);
}

bool valid_map(int fd)
{
	char	*row;
	char	**cols;
	int		col_len;

	row = get_row(fd);
	col_len = -1;

	while (row)
	{
		cols = ft_split(row, ' ');
		if (col_len == -1)
			col_len = ft_arr_length(cols);
		if (col_len != ft_arr_length(cols) || !valid_col(cols))
		{
			ft_safe_free((void **)&row);
			ft_free_split(cols);
			return (false);
		}
		ft_safe_free((void **)&row);
		ft_free_split(cols);
		row = get_row(fd);
	}
	return (true);
}
