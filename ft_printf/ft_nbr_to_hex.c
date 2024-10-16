/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:19:00 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/16 18:41:30 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_to_hex(int nbr, int upper)
{
	char	*letters;

	if (upper <= 0)
		letters = "0123456789abcdef";
	else
		letters = "0123456789ABCDEF";
	if (nbr == 0)
		return (0);
	return (1);
}
