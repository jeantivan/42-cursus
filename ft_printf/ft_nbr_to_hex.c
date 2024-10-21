/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:19:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/21 18:41:46 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_reverse_string(char *s)
{
	int		i;
	int		len;
	char	temp_letter;

	// char	*new_s;
	i = 0;
	len = ft_strlen(s);
	while (i < (len / 2))
	{
		temp_letter = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp_letter;
		i++;
	}
	return (s);
}
// TODO: convertir los números negativos también
// NO TENGO NPI de como hacerlo
char	*ft_nbr_to_hex(int nbr, int upper)
{
	char	*letters;
	char	*hex;
	int		i;

	i = 0;
	hex = (char *)malloc(sizeof(char) * 16 + 1);
	if (!hex)
		return (NULL);
	if (upper <= 0)
		letters = "0123456789abcdef";
	else
		letters = "0123456789ABCDEF";
	if (nbr == 0)
		hex[i] = '0';
	else
	{
		while (nbr > 0)
		{
			hex[i++] = letters[nbr % 16];
			nbr /= 16;
		}
		ft_reverse_string(hex);
	}
	return (hex);
}
