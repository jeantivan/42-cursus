/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:16:46 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/03 15:19:57 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int			sign;
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

int	ft_sqrt(int num)
{
	int	left;
	int	right;
	int	mid;

	if (num < 0)
		return (-1);
	if (num == 0 || num == 1)
		return (num);
	left = 1;
	right = (num >> 1) + 1;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (mid == num / mid)
			return (mid);
		if (mid <= num / mid)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (right);
}
