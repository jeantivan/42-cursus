/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:17:40 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/24 18:17:42 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
