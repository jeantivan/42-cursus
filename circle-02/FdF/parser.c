/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:05:23 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/18 00:19:31 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	valid_point(char *el)
{
	char	**point;

	point = ft_split(el, ',');
	if (!point)
		return (false);
	if (!valid_num(point[0]))
	{
		ft_free_split(point);
		return (false);
	}
	ft_free_split(point);
	return (true);
}

bool	valid_col(char **col, int expected_len)
{
	int	i;

	if (!col)
		return (false);
	if (ft_arr_len(col) != expected_len)
	{
		ft_free_split(col);
		return (false);
	}
	i = 0;
	while (col[i])
	{
		if (!valid_point(col[i]))
		{
			ft_free_split(col);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	valid_hex(char *el)
{
	int		i;
	size_t	len;

	len = ft_strlen(el);
	if (!el || el[0] != '0' || (el[1] != 'x' && el[1] != 'X'))
		return (false);
	if (len <= 3 || (len != 5 && len != 8 && len != 6 && len != 10))
		return (false);
	i = 2;
	while (el[i])
	{
		if (!(('0' <= el[i] && el[i] <= '9') || \
			('a' <= el[i] && el[i] <= 'f') || \
			('A' <= el[i] && el[i] <= 'F')))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	valid_num(char *el)
{
	int	i;

	i = 0;
	if (!el || el[i] == '\0')
		return (false);
	if ((el[i] == '-' || el[i] == '+') && el[i + 1] == '\0')
		return (false);
	if (el[i] == '-' || el[i] == '+')
		i++;
	while (el[i])
	{
		if (!ft_isdigit(el[i]))
			return (false);
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
	if (raw_row[len - 1] != '\n')
		return (raw_row);
	row = ft_substr(raw_row, 0, len - 1);
	ft_safe_free((void **)&raw_row);
	return (row);
}
