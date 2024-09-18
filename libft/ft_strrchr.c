/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:16:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/18 17:16:53 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = (int)ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			return (str + i);
		}
		i--;
	}
	return (NULL);
}
