/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:51:19 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/04 19:49:55 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlength(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_reverse_string(char *s)
{
	int		i;
	int		len;
	char	temp_letter;

	i = 0;
	len = ft_strlength(s);
	while (i < (len / 2))
	{
		temp_letter = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp_letter;
		i++;
	}
	return (s);
}
