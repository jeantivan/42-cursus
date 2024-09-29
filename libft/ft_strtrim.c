/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:00:15 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/29 12:54:02 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*n_str;
	size_t	n_str_len;
	int		start;
	int		i;
	int		end;

	len = ft_strlen(s1);
	/* Paso 1. Encontrar start */
	start = 0;
	i = 0;
	char *c_in_set;
	//printf("** SET: %s\n\n", set);
	//printf("** S1 LEN: %zu\n\n", len);

	//printf("\n Paso 1. Encontrar start \n");
	while (s1[i] != '\0')
	{
		c_in_set = ft_strchr(set, s1[i]);
		//printf("---i: %i, s[i]: %c\n", i, s1[i]);
		//printf("--set: %s, ft_strchr(set, s1[i]): %s\n", set,c_in_set);
		if(!c_in_set)
			break ;
		start = i +1;
		i++;
	}
	//printf("Start: %i\n", start);

	/* Paso 2: Encontrar end*/
	//printf("\n Paso 2: Encontrar end \n");
	i = len;
	while (i != 0)
	{
		c_in_set = ft_strchr(set, s1[i]);
		//printf("---i: %i, s[i]: %c\n", i, s1[i]);
		//printf("--set: %s, ft_strchr(set, s1[i]): %s\n", set,c_in_set);
		if(!c_in_set)
			break ;
		end = i;
		i--;
	}
	//printf("End: %i\n", end);
	n_str_len = end - start;
	//printf("n_str_len: %zu\n", n_str_len);

	n_str = ft_substr(s1, start, n_str_len);
	//printf("New_str: %s\n", n_str);
	return (n_str);
}
