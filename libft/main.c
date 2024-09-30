/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:48:08 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/30 19:10:05 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	/* const char	str[] = " lorem ipsum dolor sit amet";
	const char	set[] = "l "; */

/* 	printf("ft_strtrim(\"abcd\", \"\") = \"%s\"\n", ft_strtrim("abcd", ""));
	printf("ft_strtrim(\"tripouille   xxx\", \" x\") = \"%s\"\n", ft_strtrim("tripouille   xxx", " x"));
	printf("ft_substr(\"hola\", 0, 18446744073709551615) = \"%s\"\n", ft_substr("hola", 0, 184467440)); */

	char s2[] = "xteste";

//char s[] = "tripouille";
	printf("%s\n", strrchr(s2, 'x'));
	printf("%s\n", ft_strrchr(s2, 'x'));
	return (0);
}
