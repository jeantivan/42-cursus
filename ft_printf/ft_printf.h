/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:20:33 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/21 18:42:53 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *s, ...);
char	*ft_nbr_to_hex(int nbr, int uppercase);
/* Utils */
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nbr);
#endif /* ft_printf.h */
