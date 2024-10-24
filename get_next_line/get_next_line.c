/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:34:26 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/24 20:45:58 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_has_breakline(const char *s)
{
	if (!ft_strchr(s, '\n'))
		return (0);
	return (1);
}

static char	*ft_proccess_line(int fd, char *buff)
{
	ssize_t	bytes_readed;
	char	*data_readed;
	char	*temp;
	int	i;

	data_readed = malloc(BUFFER_SIZE);
	temp = buff;
	i = 0;
	while(!ft_has_breakline(temp))
	{
		i++;
		bytes_readed = read(fd, data_readed, BUFFER_SIZE);
		if (bytes_readed <= 0)
			return (NULL);
		printf(ANSI_COLOR_MAGENTA"data_readed: %s\n"ANSI_COLOR_RESET, data_readed);
		temp = ft_strjoin(temp, data_readed);
		printf("temp: %s\n", temp);
		free(data_readed);
		data_readed = malloc(BUFFER_SIZE);

	}
	printf("Archive readed %i times\n", i);
	return (temp);
}
static char *ft_extract_line(char **buff)
{
	size_t	first_oc;
	size_t	buff_len;
	char	*line;
	char	*temp;

	first_oc = 0;
	buff_len = ft_strlen(*buff);
	temp = *buff;
	while (temp[first_oc] != '\n')
		first_oc++;
	//printf("Hola 3\n first_oc: %zu\n", first_oc);
	if (first_oc == buff_len)
		return (*buff);
	line = ft_substr((char const *)*buff, 0, first_oc + 1);
	temp = ft_substr((char const *)*buff, first_oc + 1, buff_len);
	free(*buff);
	*buff = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff = "";
	//static int	passes = 0;
	char		*next_line;

	//printf(ANSI_COLOR_BLUE"-- Getting line nro: %i---\n"ANSI_COLOR_RESET, passes);
	if (!ft_has_breakline(buff))
	{
		//printf(ANSI_COLOR_RED"buff is empty or do not has a break line\n"ANSI_COLOR_RESET);
		//printf("proccessing...\n");
		buff = ft_proccess_line(fd, buff);
		//printf("buff after proccessing ");
		//printf(ANSI_COLOR_CYAN"%s\n"ANSI_COLOR_RESET, buff);
	}

		/* printf("---- BUFF IS NOT EMPTY ----\n");
		printf("Current buff: ");
		printf(ANSI_COLOR_YELLOW"%s\n"ANSI_COLOR_RESET, buff); */
		//printf("Extracting line...\n");
		next_line = ft_extract_line(&buff);
		/* printf(ANSI_COLOR_GREEN"Extracted line: %s\n"ANSI_COLOR_RESET, next_line);
		printf(ANSI_COLOR_MAGENTA"Remaining buff: %s\n"ANSI_COLOR_RESET, buff); */
	//passes++;
	return (next_line);
}
