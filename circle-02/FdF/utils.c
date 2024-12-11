/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:09:46 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/11 23:57:41 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_arr_length(char **arr)
{
	size_t len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

bool	val_hex(char *el)
{
	int	i;

	if (!el || ft_strlen(el) != 8 || el[0] != '0' || (el[1] != 'x' && el[1] != 'X'))
		return (false);
	i = 2;
	while (el[i])
	{
		if (!(('0' <= el[i] && el[i] <= '9') || \
			('a'<= el[i] && el[i] <= 'f') || \
			('A' <= el[i] && el[i] <= 'F')))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	val_num(char *el)
{
	int	i;

	i = 0;
	if (!el || el[i] == '\0')
		return (false);
	if ((el[i] == '-' || el[i] == '+') && el[i + 1] == '\0')
		return (false);
	if (el[i] == '-' || el[i] == '+')
		i++;
	while (el[i]) {
		if (!ft_isdigit(el[i]))
			return (false);
		i++;
	}
	return (true);
}

int get_color(char *color)
{
	int			r;
	int			g;
	int 		b;
	char 		base[] ="0123456789ABCDEF";

	if (!val_hex(color))
		return (DEFAULT_COLOR);
	r = ft_atoi_base(color + 2, base);
	g = ft_atoi_base(color + 4, base);
	b = ft_atoi_base(color + 6, base);
	return (*(int *)(unsigned char [4]){b, g, r, 0xFF});
}
