/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:41 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/03 14:07:10 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_memory(char **arr)
{
	int	i;

	i = 0;
	while (arr[i++])
		free(arr[i]);
	free(arr);
}

static int	ft_find_n_of_el(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static char	**ft_save_str_pieces(const char *s, char c, char **arr)
{
	int	pace;
	int	i;
	int	start;

	pace = 0;
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			arr[pace++] = ft_substr(s, start, i - start + 1);
			if (!arr[pace - 1])
			{
				ft_free_memory(arr);
				return (NULL);
			}
		}
		if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
			start = i + 1;
		i++;
	}
	arr[pace] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		n_of_el;
	char	**arr;

	n_of_el = ft_find_n_of_el(s, c);
	arr = (char **)malloc((n_of_el + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_save_str_pieces(s, c, arr);
	return (arr);
}
