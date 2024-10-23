/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:20:33 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/23 16:06:13 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

int		ft_printf(char const *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nbr);
int		ft_putnbr_uns(unsigned int nbr);
int		ft_putpointer(void *p);
int		ft_puthex(int nbr, int upper);
/* Utils */
size_t	ft_strlen(const char *s);
char	*ft_reverse_string(char *s);
#endif /* ft_printf.h */
