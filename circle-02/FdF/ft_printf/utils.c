/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:51:19 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/02 16:53:11 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reverse_string(char *s)
{
	int		i;
	int		len;
	char	temp_letter;

	i = 0;
	len = ft_strlen(s);
	while (i < (len / 2))
	{
		temp_letter = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp_letter;
		i++;
	}
	return (s);
}
