/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:46 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/03 00:10:44 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

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

long int	ft_atol(const char *nptr)
{
	int	sign;
	long int	result;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		result = result * 10;
		result = result + (*nptr - 48);
		nptr++;
	}
	return (sign * result);
}

void		set_indexes(t_stack *stack)
{
	int	curr_min = INT_MAX;
	int	switcher = 1;
	int	index = 0;
	t_list	*min_node;
	t_list	*curr_node;

	if (stack->size <= 1)
		return ;

	while (switcher)
	{
		switcher = 0;
		curr_node = stack->head;
		curr_min = INT_MAX;
		while(curr_node)
		{
			if (peek(curr_node) < curr_min && curr_node->index == -1)
			{

				min_node = curr_node;
				curr_min = peek(min_node);
			}
			curr_node = curr_node->next;
		}
		if (min_node->index == -1)
		{
			min_node->index = index;
			index++;
			switcher = 1;
		}

	}
}
