/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:06:38 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/23 13:41:32 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static char	*ft_pointer_to_hex(uintptr_t ptr, const char *letters)
{
	char	*hex;
	int		i;

	i = 0;
	hex = (char *)malloc(sizeof(char) * (16 + 1));
	if (!hex)
		return (NULL);
	if (ptr == 0)
		hex[i++] = '0';
	else
	{
		while (ptr > 0)
		{
			hex[i++] = letters[ptr % 16];
			ptr /= 16;
		}
	}
	hex[i] = '\0';
	ft_reverse_string(hex);
	return (hex);
}

int	ft_putpointer(void *p)
{
	int			tot;
	uintptr_t	ptr;
	char		*address;

	if (p == NULL)
		return (ft_putstr("(nil)"));
	tot = ft_putstr("0x");
	if (tot == -1)
		return (-1);
	ptr = (uintptr_t)p;
	address = ft_pointer_to_hex(ptr, HEX_LOWER);
	tot += ft_putstr(address);
	free(address);
	address = NULL;
	return (tot);
}
