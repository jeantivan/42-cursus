/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:37:14 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/19 17:37:15 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

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

