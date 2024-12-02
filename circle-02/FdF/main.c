/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/02 16:44:20 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

int	main(void)
{
	int		fd;
	char	*line;
	char	*line_cpy;

	fd = open("./test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	ft_printf("Line %s", line);
	line_cpy = ft_strdup(line);
	ft_printf("Line_cpy %s", line_cpy);
	ft_safe_free((void **)&line);
	ft_safe_free((void **)&line_cpy);
	close(fd);
	return (0);
}
