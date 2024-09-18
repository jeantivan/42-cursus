/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:50:57 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/18 16:50:58 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	str = (char *)s;
	str_len = ft_strlen(str);
	i = 0;
	while (i <= str_len)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
