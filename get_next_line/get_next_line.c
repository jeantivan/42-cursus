/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:34:26 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/28 18:19:36 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_safe_free(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
static int	ft_has_breakline(const char *s)
{
	if (!s)
		return (0);
	if (!ft_strchr(s, '\n'))
		return (0);
	return (1);
}

static ssize_t	ft_fill_buff(int fd, char **buff)
{

	ssize_t	bytes_readed;
	char	*data_readed;
	char	*temp;

	if (!*buff)
		*buff = "";
	data_readed = (char *)malloc(BUFFER_SIZE + 1);
	if (!data_readed)
		return (-1);
	while (!ft_has_breakline(temp))
	{
		bytes_readed = read(fd, data_readed, BUFFER_SIZE);
		if (bytes_readed <= 0)
		{
			ft_safe_free((void *)data_readed);
			return (bytes_readed);
		}
		data_readed[bytes_readed] = '\0';
		temp = ft_strjoin(*buff, data_readed);
		ft_safe_free((void *)(*buff));
		*buff = temp;
	}
	ft_safe_free((void *)data_readed);
	bytes_readed = 0;
	return (bytes_readed);
}

static char *ft_extract_line(char **buff)
{
	size_t	first_oc;
	size_t	buff_len;
	char	*line;
	char	*temp;

	if (*buff == NULL)
		return (NULL);
	first_oc = 0;
	buff_len = ft_strlen(*buff);
	while ((*buff)[first_oc] != '\n' && (*buff)[first_oc])
		first_oc++;
	if ((*buff)[first_oc] == '\n')
		first_oc++;
	line = ft_substr(*buff, 0, first_oc);
	temp = ft_substr(*buff, first_oc, buff_len - first_oc);
	free(*buff);
	*buff = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	char	*next_line;
	static char	*buff = NULL;
	ssize_t		filled;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff || !ft_has_breakline(buff))
	{
		printf("Buff empty or without breakline\n");
		filled = ft_fill_buff(fd, &buff);
		if(filled <= 0)
		{
			ft_safe_free((void **)buff);
			return (NULL);
		}
	}
	next_line = ft_extract_line(&buff);
	return (next_line);
}
