/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:46 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/15 12:56:21 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_safe_free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

void	*ft_free_split(char **splited)
{
	int	i;

	i = 0;
	if (!splited)
		return (NULL);
	while (splited[i])
	{
		ft_safe_free((void **)&splited[i]);
		i++;
	}
	return (ft_safe_free((void **)&splited));
}

int	arr_length(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}
