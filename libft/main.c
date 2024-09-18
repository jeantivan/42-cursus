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
#include <string.h>

int	main(void)
{
	const char	*str;

	str = "Hola mundo!";
	printf("%s", ft_strrchr(str, 'H'));
	return (0);
}
