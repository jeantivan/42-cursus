/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:53:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/22 19:17:16 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_nbr_to_hex(unsigned int nbr, const char *letters)
{
	char	*hex;
	int		i;

	i = 0;
	hex = (char *)malloc(sizeof(char) * (16 + 1));
	if (!hex)
		return (NULL);
	if (nbr == 0)
		hex[i++] = '0';
	else
	{
		while (nbr > 0)
		{
			hex[i++] = letters[nbr % 16];
			nbr /= 16;
		}
	}
	hex[i] = '\0';
	ft_reverse_string(hex);
	return (hex);
}

int	ft_puthex(int nbr, int upper)
{
	int		tot;
	char	*hex;

	tot = 0;
	if (upper > 0)
		hex = ft_nbr_to_hex((unsigned int)nbr, HEX_UPPER);
	else
		hex = ft_nbr_to_hex((unsigned int)nbr, HEX_LOWER);
	tot += ft_putstr(hex);
	free(hex);
	return (tot);
}
