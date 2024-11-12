/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:46 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/12 16:47:04 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

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
	ft_printf("arr = {");
	while (arr[i])
	{
		ft_printf("%s, ", arr[i]);
		i++;
	}
	ft_printf("NULL }\n");
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
	return (count);
}
