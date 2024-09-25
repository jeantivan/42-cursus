/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:48:08 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/18 17:48:10 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_test_striteri(unsigned int i, char *c)
{
	printf("index: %i, char: %c\n", i, *c);
}

char	ft_test_strmapi(unsigned int index, char c)
{
	if (index % 2 == 0 && ('a' <= c && c <= 'z'))
	{
		printf("index: %i, char: %c\n", index, c);
		return (c - 32);
	}
	return ('-');
};


int		main(int argc, const char *argv[])
{
	int	arg;
	alarm(5);

	if (argc == 1)
		return (0);
	if ((arg = atoi(argv[1])) == 1)
	{
		printf("-----Testing ft_striteri-----\n");
		ft_striteri("Hola mundo!", ft_test_striteri);
	}
	else if (arg == 2)
	{
		printf("-----Testing ft_strmapi-----\n");
		printf("%s\n", ft_strmapi("Hola mundo!", ft_test_strmapi));

	}

	return (0);
}
