/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:50:58 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/10 20:01:28 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_YELLOW "\x1b[33m"
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN "\x1b[36m"
# define ANSI_COLOR_RESET "\x1b[0m"

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_strlen_gnl(const char *s);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *s);

#endif /* get_next_line.h */
