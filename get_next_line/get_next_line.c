/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:34:26 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/03 12:22:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	int		i;
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		i = 0;
		while (buff[i] != '\n')
		{
			ft_putchar(buff[i]);
			if (buff[i + 1] == '\n')
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
