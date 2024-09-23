/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:51:14 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/23 18:51:15 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*mem;
	size_t	i;

	i = 0;
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	while (i < nmemb)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
