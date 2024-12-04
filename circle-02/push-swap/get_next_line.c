/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:34:26 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/04 22:51:29 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_safe_free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
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

	data_readed = (char *)malloc(BUFFER_SIZE + 1);
	if (!data_readed)
		return (-1);
	temp = *buff;
	while (!ft_has_breakline(temp))
	{
		bytes_readed = read(fd, data_readed, BUFFER_SIZE);
		if (bytes_readed <= 0)
		{
			free(data_readed);
			return (bytes_readed);
		}
		data_readed[bytes_readed] = '\0';
		temp = ft_strjoin(*buff, data_readed);
		gnl_safe_free((void **)buff);
		*buff = temp;
	}
	free(data_readed);
	return (bytes_readed);
}

static char	*ft_extract_line(char **buff)
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
	if (!line)
		return (NULL);
	temp = ft_substr(*buff, first_oc, buff_len - first_oc);
	if (!temp)
	{
		gnl_safe_free((void **)&temp);
		return (NULL);
	}
	gnl_safe_free((void **)buff);
	*buff = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buff = NULL;
	ssize_t		filled;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
	{
		buff = ft_strdup("");
		if (!buff)
			return (NULL);
	}
	if (!ft_has_breakline(buff))
	{
		filled = ft_fill_buff(fd, &buff);
		if (filled < 0)
			return (gnl_safe_free((void **)&buff));
		else if (filled == 0 && buff[0] == '\0')
			return (gnl_safe_free((void **)&buff));
	}
	next_line = ft_extract_line(&buff);
	if (!next_line)
		return (gnl_safe_free((void **)&buff));
	return (next_line);
}
