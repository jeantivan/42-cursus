/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:01:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/10/21 15:34:59 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

void	ft_test_base(void);
void	ft_test_null(void);
void	ft_test_char(void);
void	ft_test_string(void);
void	ft_test_digit(void);
void	ft_test_int(void);
void	ft_test_u(void);
void	ft_test_x(void);
void	ft_test_p(void);
void	ft_test_void(void);

#endif
