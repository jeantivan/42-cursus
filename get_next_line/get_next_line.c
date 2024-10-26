/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:34:26 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/26 11:00:46 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_has_breakline(const char *s)
{
	if (!ft_strchr(s, '\n'))
		return (0);
	return (1);
}

static ssize_t	ft_fill_buff(int fd, char **buff)
{
	ssize_t	bytes_readed;
	char	*data_readed;
	char	*temp;
	char	*new_buff;
	int	switcher;

	data_readed = (char *)malloc(BUFFER_SIZE + 1);
	if (!data_readed)
		return (-1);
	switcher = 0;
	new_buff = ft_strjoin(*buff, "");
	while (!ft_has_breakline(new_buff))
	{
		bytes_readed = read(fd, data_readed, BUFFER_SIZE);
		if (bytes_readed < 0)
		{
			printf(ANSI_COLOR_RED" --- Error will reading --- \n"ANSI_COLOR_RESET);
			free(data_readed);
			return (-1);
		}
		if (bytes_readed == 0)
		{
			printf(ANSI_COLOR_YELLOW" --- End of file --- \n"ANSI_COLOR_RESET);
			switcher = 1;
			break ;
		}
		data_readed[bytes_readed] = '\0';
		temp = ft_strjoin(new_buff, data_readed);
		free(new_buff);
		new_buff = temp;
		free(temp);
	}
	if (switcher == 1)
	{
		printf("Temp at end of file: \n");
		printf(ANSI_COLOR_MAGENTA"%s"ANSI_COLOR_RESET, temp);
	}
	*buff = ft_strjoin(new_buff, "");
	free(new_buff);
	free(temp);
	free(data_readed);
	return (bytes_readed);
}
static char	*ft_search_breakline(int fd, char *buff)
{
	ssize_t	bytes_readed;
	char	*data_readed;
	char	*temp;
	//int	times;

	temp = buff;
	data_readed = malloc(BUFFER_SIZE + 1);
	if (!data_readed)
		return (NULL);
	//times = 0;
	while(!ft_has_breakline(temp))
	{
		//printf(ANSI_COLOR_YELLOW"Times readed %i\n"ANSI_COLOR_RESET, times++);

		bytes_readed = read(fd, data_readed, BUFFER_SIZE);
		if (bytes_readed <= 0)
		{
			//printf("Bytes readed %zu\n", bytes_readed);
			//printf(ANSI_COLOR_RED"Will break\n"ANSI_COLOR_RESET);
			//data_readed[0] = '\0';
			return (NULL);
		}
		data_readed[bytes_readed] = '\0';
		//printf("Data readed: %s\n", data_readed);
		//printf("Temp: %s\n", temp);
		temp = ft_strjoin(temp, data_readed);
		free(temp);
		//printf("Temp after join: %s\n", temp);
	}
	/* if(data_readed[0] == '\0')
	{
		//printf("last readed 1");
		temp = ft_strjoin(temp, "");
	}
	else
	{
		//printf("last readed 2\n");
		//printf("bytes_readed %zu\n", bytes_readed);
		data_readed[bytes_readed] = '\0';
		temp = ft_strjoin(temp, data_readed);
		free(data_readed);
	} */
	temp = ft_strjoin(temp, "");
	//printf("Last readed 3\n");
	//printf("Last temp: %s", temp);
	////printf("Bytes readed: %zu\n", bytes_readed);
	return (temp);
}
/* static ft_temp_func(int fd)
{

} */

static char *ft_extract_line(char **buff)
{
	//pqrintf("Extract line 0");
	size_t	first_oc;
	size_t	buff_len;
	char	*line;
	char	*temp;

	//printf("Extract line 1");
	first_oc = 0;
	buff_len = ft_strlen(*buff);
	temp = *buff;
	//printf("Extract line 2");
	while (temp[first_oc] != '\n' || temp[first_oc] != '\0')
		first_oc++;
	//printf("Extract line 3");
	if (first_oc == buff_len)
		return (*buff);
	line = ft_substr((char const *)*buff, 0, first_oc + 1);
	temp = ft_substr((char const *)*buff, first_oc + 1, buff_len);
	free(*buff);
	*buff = temp;
	return (line);
}

char	*ft_process_line(int fd)
{
	static char	*buff = "";
	char		*next_line;
	// TODO: Aquí  no se que
	if (!ft_has_breakline(buff))
	{
		//printf("\nProcess line 1\n");
		buff = ft_search_breakline(fd, buff);
		if (buff == NULL)
		{ return (NULL); }
		//printf(ANSI_COLOR_MAGENTA"Buff: %s"ANSI_COLOR_RESET, buff);
	}
	//printf("\nProcess line 2\n");
	next_line = ft_extract_line(&buff);
	//printf("\nProcess line 3\n");

	return (next_line);
}

char	*get_next_line(int fd)
{
	char	*next_line;
	static char	*buff = "";
	ssize_t filled;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("Bad file descriptor or BUFFER_SIZE\n");
		return (NULL);
	}
	// llenamos buff
	if (buff[0] == '\0' || !ft_has_breakline(buff))
	{
		printf("Buff empty or without breakline\n");
		filled = ft_fill_buff(fd, &buff);
		if(filled == -1)
			return (NULL);
		else if (filled == 0)
			printf("Current buffer at end of file: \n");
		{
			printf(ANSI_COLOR_MAGENTA"%s"ANSI_COLOR_RESET, buff);
			next_line = ft_extract_line(&buff);
		}
	} else
	{
		printf(ANSI_COLOR_BLUE"Processing current buffer\n"ANSI_COLOR_RESET);
		next_line = ft_extract_line(&buff);
	}
	return (next_line);
}
