/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:59:29 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/12 17:34:38 by jtivan-r         ###   ########.fr       */
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
# define DEFAULT_COLOR "0xFFFFFF"


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
void		ft_error(char *error_message);

/* Utils */
int			ft_arr_length(char **arr);
bool		val_hex(char *el);
bool		val_num(char *el);
int			get_color(char *color);

/* Parseo del map */
bool		valid_map(int fd);
t_point		**parse_map(char *path_to_file);
char		*get_row(int fd);

/* Points */
t_point		**get_points(const char *path_to_file, int dimensions);

#endif /* fdf.h */
