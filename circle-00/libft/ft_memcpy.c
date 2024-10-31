/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:02:07 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/19 22:02:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_cpy;
	unsigned char		*dst;
	size_t				i;

	i = 0;
	src_cpy = (const unsigned char *)src;
	dst = (unsigned char *)dest;
	while (i < n)
	{
		dst[i] = src_cpy[i];
		i++;
	}
	return (dst);
}
