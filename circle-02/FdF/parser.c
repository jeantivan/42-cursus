/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:05:23 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/12 18:49:06 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

char	*get_row(int fd)
{
	char	*raw_row;
	char	*row;
	size_t	len;

	raw_row = get_next_line(fd);
	if (!raw_row)
		return (NULL);
	len = ft_strlen(raw_row);
	printf("len: %zu\n", len);
	row = ft_substr(raw_row, 0, len - 1);
	ft_safe_free((void **)&raw_row);
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


int	get_map_dimensions(char *path_file)
{
	int		lines;
	int		cols;
	char	*row;
	char	**col;
	int		fd;

	lines = 0;
	fd = open(path_file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Can't open file\n");
		return (-1);
	}
	row = get_row(fd);
	cols = -1;
	while (row)
	{
		ft_printf("row: %s-\n", row);
		lines++;
		col = ft_split(row, ' ');
		if (cols == -1)
			cols = ft_arr_length(col);
		if (cols != ft_arr_length(col) || !valid_col(col))
		{
			ft_printf("%s", row);
			ft_printf("lines %i Cols %i cur_cols %i\n", lines, cols, ft_arr_length(col));
			ft_free_split(col);
			ft_safe_free((void **)&row);
			close(fd);
			return (0);
		}
		ft_free_split(col);
		ft_safe_free((void **)&row);
		row = get_next_line(fd);
	}
	close(fd);
	return (cols * lines);
}

t_point	**parse_map(char *path_to_file)
{
	t_point		**points;

	int dimensions = get_map_dimensions(path_to_file);

	if (dimensions <= 0)
	{
		ft_printf("Dimensions %i\n", dimensions);
		ft_error("Invalid map");
	}
	ft_printf("Dimensions %i\n", dimensions);
	points = get_points(path_to_file, dimensions);
	if (!points)
		ft_error("While parsing the map");
	return (points);
}
