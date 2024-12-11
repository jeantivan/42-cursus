/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/11 23:58:09 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

int	main(int ac, char **av)
{
	char	*file;
	int		fd;

	if (ac != 2)
		return (1);
	file = av[1];
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Bad file");

	clock_t inicio, fin;
	double tiempo_usado;

	inicio = clock();
	bool is_valid_map = valid_map(fd);
	ft_printf("Valid map: %i\n", is_valid_map);
	fin = clock();
    // Calcular el tiempo de ejecución
    tiempo_usado = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
    printf("Chequear el mapa tardó: %.8f segundos\n", tiempo_usado);

	close(fd);
	return (0);
}
