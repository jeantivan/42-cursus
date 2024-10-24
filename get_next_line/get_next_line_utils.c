/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:33:26 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/24 18:14:43 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (c >= 256)
		c = c % 256;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dest_length;
	size_t	len_to_copy;
	size_t	counter;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	if (size <= dest_length)
		return (size + src_length);
	len_to_copy = size - dest_length - 1;
	if (len_to_copy > src_length)
		len_to_copy = src_length;
	counter = 0;
	while (counter < len_to_copy)
	{
		dst[dest_length + counter] = src[counter];
		counter++;
	}
	dst[dest_length + counter] = '\0';
	return (dest_length + src_length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	ft_strlcat(new_str, s1, total_len + 1);
	ft_strlcat(new_str, s2, total_len + 1);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	r_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = (char *)malloc((1) * sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	r_len = s_len - start;
	if (len < r_len)
		r_len = len;
	substr = (char *)malloc((r_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	ft_strlcat(substr, (s + start), r_len + 1);
	return (substr);
}
