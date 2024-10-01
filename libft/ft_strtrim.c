/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:00:15 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/01 20:04:02 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start(char const *s1, char const *set)
{
	int	start;
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	start = i;
	return (start);
}

static int	ft_find_end(char const *s1, char const *set)
{
	int	end;
	int	i;

	i = ft_strlen(s1);
	while (i != 0)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		end = i;
		i--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*n_str;
	size_t	n_str_len;
	int		start;
	int		end;

	if (!set || set[0] == '\0')
		return (ft_strdup(s1));
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	n_str_len = end - start;
	n_str = ft_substr(s1, start, n_str_len);
	return (n_str);
}
