/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:59:29 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/03 17:24:48 by jtivan-r         ###   ########.fr       */
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

typedef struct s_state
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		*map;
	bool		dots;
	bool		lines;
}	t_state;

typedef struct s_neighbors
{
	t_point	*right;
	t_point	*bottom;
	bool	has_right;
	bool	has_bottom;
}	t_neighbors;

/* Error */
void		ft_error(char *error_message);
void		*clean_with_error(t_state *state, char *error_message);

/* Utils */
int			ft_arr_len(char **arr);
bool		valid_hex(char *el);
bool		valid_num(char *el);
uint32_t	get_color(char *color);

/* Parseo del map */
bool		valid_col(char **col, int expected_len);
bool		valid_point(char *el);
char		*get_row(int fd);

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

/* Map */
t_map		*init_map(t_map *map, char *file);
void		clean_map(t_map *map);
void		draw_map(t_state *state, bool fit);

/* Map utils */
void		get_map_dimensions(char *path_to_file, t_map *map);
void		prepare_map(t_map *map, t_point *proyection, size_t len, bool fit);

/* Proyection */
void		get_center_coords(t_point *points, size_t len, float center[2]);
void		ortho_projection(t_point *points, size_t len);
void		scale_points(t_point *points, size_t len, float factor);
void		translate_points(t_point *points, size_t len, \
float c[2], float m[2]);
void		project_points(t_point *points, t_point *proyection, \
size_t len, float ang[3]);

/* Drawing*/
void		put_pixel(mlx_image_t *image, int x, int y, uint32_t color);
void		dda(mlx_image_t *image, t_point point0, t_point point1);
void		draw_points(t_state *state, t_point *points, size_t len);
void		join_points(t_state *state, t_point *proyection);
void		draw_dot(mlx_image_t *image, t_point p);

/* Draw utils */
int			get_index(int x, int y, int cols);
int			is_valid_point(int x, int y, int rows, int cols);
t_neighbors	get_neighbors(int x, int y, t_map *map, t_point *proyection);

/* Hooks */
void		close_hook(void *param);
void		key_hook(mlx_key_data_t keydata, void *param);
void		scroll_hook(double xdelta, double ydelta, void *param);

/* Handlers */
void		handle_translate(uint32_t key, t_state *state);
void		handle_reset(t_state *state);
void		handle_scale(double ydelta, t_state *state);
void		handle_rotate(mlx_key_data_t keydata, t_state *state);
void		handle_mode(uint32_t key, t_state *state);
void		handle_view(uint32_t key, t_state *state);

#endif /* fdf.h */
