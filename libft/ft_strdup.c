/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:08:02 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/23 19:08:03 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*str_dup;
	size_t	i;

	i = 0;
	str_len = ft_strlen(s);
	str_dup = (char *)malloc((str_len + 1) * sizeof(char));
	if (str_dup == NULL)
		return (NULL);
	while (i < str_len)
	{
		str_dup[i] = s[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}
