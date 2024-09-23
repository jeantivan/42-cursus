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

int main()
{
    char	src[] = "lorem ipsum dolor sit amet";
    char	*dest;

   	dest = src + 1;
    if (dest != ft_memmove(dest, src, 8))
		write(1, "dest's adress was not returned\n", 31);
	write(1, dest, 22);
    write(1, "\n", 1);
    return 0;
}
