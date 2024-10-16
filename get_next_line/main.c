/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:33:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/03 12:00:57 by jtivan-r         ###   ########.fr       */
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
	get_next_line(fd);
	return (0);
}
