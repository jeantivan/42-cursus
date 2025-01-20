/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:59:29 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/20 16:44:09 by jtivan-r         ###   ########.fr       */
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
#  define M_PI 3.14159265358979323846
# endif
# ifndef WIN_W
#  define WIN_W 1280
# endif
# ifndef WIN_H
#  define WIN_H 720
# endif
# ifndef MARGIN
#  define MARGIN 20
# endif
# define DEFAULT_COLOR "0x000000FF"
# define X 0
# define Y 1
# define Z 2

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

typedef struct s_neighbors
{
	t_point	*right;
	t_point	*bottom;
	bool	has_right;
	bool	has_bottom;
}	t_neighbors;

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
bool		points_fit(t_point *points, size_t len);
void		copy_points(t_point *dst, t_point *src, size_t len);

/* Matrix */
void		matrix_init(float (*matrix)[3]);
t_point		matmul(float matrix[3][3], t_point point);
t_point		rotate_x(t_point point, float ang);
t_point		rotate_y(t_point point, float ang);
t_point		rotate_z(t_point point, float ang);

/* Proyection */
void		get_center_coords(t_point *points, size_t len, float center[2]);
void		ortho_proyection(t_point *points, size_t len);
void		scale_points(t_point *points, size_t len, float factor);
void		translate_points(t_point *points, size_t len, float move[2]);
void		proyect_points(t_point *points, t_point *proyection, \
size_t len, float ang[3]);

/* Drawing*/
void		put_pixel(mlx_image_t *image, int x, int y, uint32_t color);
void		dda(mlx_image_t *image, t_point point0, t_point point1);
void		draw_points(mlx_image_t *image, t_point *points, size_t len);
void		join_points(mlx_image_t *image, t_map *map);
void		draw_dot(mlx_image_t *image, t_point p);

/* Draw utils */
int			get_index(int x, int y, int cols);
int			is_valid_point(int x, int y, int rows, int cols);
t_neighbors	get_neighbors(int x, int y, t_map *map);

#endif /* fdf.h */
