/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:59:29 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/11 20:24:14 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "MLX42/MLX42.h"
# include <stdbool.h>
# define WIDTH 720
# define HEIGHT 500
# define BPP sizeof(int32_t)
# define DEFAULT_COLOR 255


typedef struct s_matrix_size
{
	int	rows;
	int	cols;
}	t_matrix_size;

/* Point*/
typedef struct s_point
{
	int x;
	int y;
	int z;
	int color;
}	t_point;


/* Error */
void	ft_error(char *error_message);

/* Utils */
int			ft_arr_length(char **arr);
bool 		val_hex(char *el);
bool		val_num(char *el);

/* Parseo del map */
bool		valid_map(int fd);

#endif /* fdf.h */
