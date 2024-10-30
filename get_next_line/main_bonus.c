/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:13:24 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/30 15:52:04 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	read_file(int fd, char *path)
{
	char	*line;
	int		lines;

	lines = 0;
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

void	read_files(void)
{
	int fd_1 = open("./test/el_quijote.txt", O_RDONLY);
	int fd_2 = open("./test/test01", O_RDONLY);
	char *line_a;
	char *line_b;
	int lines = 0;

	while (++lines > 0)
	{
		line_a = get_next_line(fd_1);
		line_b = get_next_line(fd_2);
		printf(ANSI_COLOR_BLUE"%s"ANSI_COLOR_RESET, line_a);
		printf(ANSI_COLOR_YELLOW"%s"ANSI_COLOR_RESET, line_b);

		if (line_a == NULL && line_b == NULL)
			lines = -1;
		ft_safe_free((void **)&line_a);
		ft_safe_free((void **)&line_b);
	}
	ft_safe_free((void **)&line_a);
	ft_safe_free((void **)&line_b);
	close(fd_1);
	close(fd_2);
}
int	main(void)
{


	read_files();
	return (0);
}
