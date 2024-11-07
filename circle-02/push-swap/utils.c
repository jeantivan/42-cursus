/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:46 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/07 16:51:11 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

void	*ft_safe_free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

void	ft_free_split(char **splited)
{
	int	i;

	i = 0;
	if (!splited)
		return;
	while (splited[i])
	{
		ft_safe_free((void **)&splited[i]);
		i++;
	}
	ft_safe_free((void **)splited);
}

size_t arr_length(char **arr)
{
	size_t	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

void	print_arr(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

size_t	count_elements(char **inputs)
{
	size_t	count;
	int		i;
	char	**temp;

	count = 0;
	i = 1;
	while (inputs[i])
	{
		temp = ft_split(inputs[i], ' ');
		count += arr_length(temp);
		ft_free_split(temp);
		i++;
	}
	ft_free_split(temp);
	return (count);
}
