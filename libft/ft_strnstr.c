/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:17:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/24 15:17:01 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	i = 0;
	j = 0;
	l_len = ft_strlen(little);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (!ft_strncmp(big + i, little, l_len) && (i + l_len) < len)
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
