/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:02:07 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/19 22:02:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	char unsigned		*dst_cpy;
	const char unsigned	*src_cpy;

	i = 0;
	dst_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	return (dst_cpy);
} */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dst_cpy > src_cpy)
	{
		i = n;
		while (i-- > 0)
			dst_cpy[i] = src_cpy[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	}
	return (dst_cpy);
}
