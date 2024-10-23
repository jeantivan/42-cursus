/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:39:36 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/23 16:08:39 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	counter;
/*
	FILE *file = fopen("test.txt", "a");

	if (file == NULL) {
       perror("Error opening file");
       return 1;
	}
	//close(1);
	counter = ft_printf("%");
	fprintf(file, "ft_printf: Printed %i\n", counter);
	printf("\n");
	counter = printf("%");
	fprintf(file, "printf: Printed %i\n", counter);


	printf("\n");



	fclose(file);
 */
	counter = ft_printf(" %s %s ", "", "-");
	printf("\nTest: printed %i chars\n", counter);
	counter = printf(" %s %s ", "", "-");
	printf("\nTest: printed %i chars\n", counter);
	return (0);
}
