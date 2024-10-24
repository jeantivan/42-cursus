/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:33:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/24 18:54:47 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	main(void)
{
	int	fd;
	//int lines;

	//lines = 0;
	fd = open("./test/test01", O_RDONLY);
	if (fd < 0)
		return (1);
	/* while(lines <= 15)
	{
		if (lines % 2 == 0)
			printf(ANSI_COLOR_GREEN"%s"ANSI_COLOR_RESET, get_next_line(fd));
		else
			printf(ANSI_COLOR_MAGENTA"%s"ANSI_COLOR_RESET, get_next_line(fd));
		lines++;
	} */
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}
