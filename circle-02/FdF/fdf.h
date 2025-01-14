/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:59:29 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/14 19:07:03 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "MLX42/MLX42.h"
# include <stdbool.h>
# include <math.h>
# ifndef M_PI
#  define M_PI (3.14159265358979323846)
# endif
# ifndef WIN_W
#  define WIN_W 1280
# endif
# ifndef WIN_H
#  define WIN_H 720
# endif
# define DEFAULT_COLOR "0x000000FF"
# define MARGIN 10
# define X 0
# define Y 1
# define Z 2

typedef struct s_screen_config
{
	int		width;
	int		height;
	int		total_points;
	double	padding;
}	t_screen_config;

typedef struct s_projection_offset
{
	double	x_offset;
	double	y_offset;
	double	spacing;
}	t_projection_offset;

typedef struct s_point
{
	float		coords[3];
	uint32_t	color;
}		t_point;
typedef struct s_map
{
	int			rows;
	int			cols;
	t_point		*points;
	float		center[2];
	float		x_center;
	float		y_center;
	float		scale;
	float		x_offset;
	float		y_offset;
	float		ang[3];
}				t_map;

typedef struct s_meta
{
	t_map		*map;
	float		*x_center;
	float		*y_center;
	float		spacing;
}	t_meta;

/* Error */
void		ft_error(char *error_message);

/* Utils */
int			ft_arr_len(char **arr);
bool		valid_hex(char *el);
bool		valid_num(char *el);
uint32_t	get_color(char *color);

/* Parseo del map */
bool		valid_col(char **col, int expected_len);
bool		valid_point(char *el);
char		*get_row(int fd);
t_map		*create_map(char *path_to_file);

/* Points */
void		get_points(int fd, t_map *map);
void		ft_show_point(t_point point);

/* Matrix */
void	matrix_init(float (*matrix)[3]);
t_point	matmul(float matrix[3][3], t_point point);
t_point	rotate_x(t_point point, float ang);
t_point	rotate_y(t_point point, float ang);
t_point	rotate_z(t_point point, float ang);

/* Drawing*/
void		drawline(mlx_image_t *image, t_point p1, t_point p2, uint32_t color);
void		join_points(mlx_image_t *image, t_map *map);

#endif /* fdf.h */
