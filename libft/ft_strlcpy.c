/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:40:07 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/19 18:40:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		size_to_cpy;
	size_t		src_len;

	size_to_cpy = size;
	src_len = ft_strlen(src);
	i = 0;
	if (size_to_cpy != 0)
	{
		while (i < size_to_cpy && src[i] == '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (src_len);
} */
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	const char	*osrc;
	size_t		nleft;

	osrc = src;
	nleft = dsize;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			*dst++ = *src++;
			if (*dst == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (dsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
