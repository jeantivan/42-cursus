/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:54:27 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/02 18:16:33 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_safe_free(void **ptr)
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
	if (!ft_strchr_gnl(s, '\n'))
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
		if (bytes_readed < 0)
		{
			free(data_readed);
			return (bytes_readed);
		}
		if (bytes_readed == 0)
			break ;
		data_readed[bytes_readed] = '\0';
		temp = ft_strjoin_gnl(*buff, data_readed);
		ft_safe_free((void **)buff);
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
	buff_len = ft_strlen_gnl(*buff);
	while ((*buff)[first_oc] != '\n' && (*buff)[first_oc])
		first_oc++;
	if ((*buff)[first_oc] == '\n')
		first_oc++;
	line = ft_substr_gnl(*buff, 0, first_oc);
	if (!line)
		return (NULL);
	temp = ft_substr_gnl(*buff, first_oc, buff_len - first_oc);
	if (!temp)
	{
		ft_safe_free((void **)buff);
		return (NULL);
	}
	ft_safe_free((void **)buff);
	*buff = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buff[1024];
	ssize_t		filled;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff[fd])
	{
		buff[fd] = ft_strdup_gnl("");
		if (!buff[fd])
			return (NULL);
	}
	if (!ft_has_breakline(buff[fd]))
	{
		filled = ft_fill_buff(fd, &buff[fd]);
		if (filled < 0)
			return (ft_safe_free((void **)&buff[fd]));
		else if (filled == 0 && buff[fd][0] == '\0')
			return (ft_safe_free((void **)&buff[fd]));
	}
	next_line = ft_extract_line(&buff[fd]);
	if (!next_line)
		return (ft_safe_free((void **)&buff[fd]));
	return (next_line);
}
