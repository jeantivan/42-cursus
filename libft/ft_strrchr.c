/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:16:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/01 19:42:57 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (c >= 256)
		c = c % 256;
	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + i));
	while (i != 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if (i == 0 && s[i] == (char)c)
		return ((char *)s);
	return (NULL);
}
