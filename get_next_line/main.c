/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:33:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/29 18:26:21 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_file(char *path)
{
	int		fd;
	char	*line;
	int		lines;

	lines = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	printf(ANSI_COLOR_YELLOW"\n --- Reading file %s fd: \
	%i ---\n"ANSI_COLOR_RESET, path, fd);
	while ((line = get_next_line(fd)) && ++lines)
	{
		if (lines % 2 == 0)
			printf(ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, line);
		else
			printf(ANSI_COLOR_MAGENTA"%s"ANSI_COLOR_RESET, line);
		ft_safe_free((void **)&line);
	}
	close(fd);
	printf(ANSI_COLOR_YELLOW"\n --- Printed %i lines ---\
	\n"ANSI_COLOR_RESET, lines);
}

int	main(void)
{
	read_file("./test/test01");
	read_file("./test/test02.txt");
	read_file("./test/test03.dict");
	read_file("./test/test04");
	read_file("./test/el_quijote.txt");
	read_file("./test/1char.txt");
	return (0);
}
