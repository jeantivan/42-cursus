/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:59:29 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/19 00:43:42 by jtivan-r         ###   ########.fr       */
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
# define WIDTH 1280
# define HEIGHT 720
# define DEFAULT_COLOR "0x000000FF"

typedef struct s_screen_config {
    int width;       // Ancho total de la ventana
    int height;      // Altura total de la ventana
    int total_points;// Número total de puntos
    double padding;  // Margen de espacio alrededor de la proyección
} t_screen_config;

typedef struct s_projection_offset {
    double x_offset;  // Desplazamiento horizontal
    double y_offset;  // Desplazamiento vertical
    double spacing;   // Espaciado entre puntos
} t_projection_offset;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	double		x_iso;
	double		y_iso;
	uint32_t	color;
}		t_point;
typedef struct s_map
{
	int			rows;
	int			cols;
	t_point		*points;
}				t_map;

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
void		ft_free_points(t_point *points);

/* Drawing*/
void drawline(mlx_image_t* image, t_point p1, t_point p2);

#endif /* fdf.h */
