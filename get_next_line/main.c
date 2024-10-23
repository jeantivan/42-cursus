/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:33:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/23 16:53:58 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("./test/test01", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("Buffer Size: %i\n", BUFFER_SIZE);
	get_next_line(fd);
	return (0);
}
