/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/19 00:45:55 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

double calculate_pixel_spacing(size_t total_points, double padding)
{
	double	points_root;
	double	base_spacing_x;
	double	base_spacing_y;
	double	spacing;

	points_root = sqrt(total_points);
	base_spacing_x = (WIDTH * (1.0 - padding)) / points_root;
	base_spacing_y = (HEIGHT * (1.0 - padding)) / points_root;
	spacing = fmin(base_spacing_x, base_spacing_y);
	return fmax(spacing, 1.0);
}

t_projection_offset calculate_centered_projection(t_screen_config *config) {
	t_projection_offset offset;

	// Calcular la raíz cuadrada del número de puntos
	double points_root = sqrt(config->total_points);

	// Redondear al siguiente entero para asegurar cubrimiento
	int grid_size = ceil(points_root);

	// Calcular espaciado base
	double base_spacing_x = (config->width * (1.0 - config->padding)) / (grid_size * 2.5);
	double base_spacing_y = (config->height * (1.0 - config->padding)) / (grid_size * 2.5);

	// Tomar el mínimo para mantener proporción
	offset.spacing = fmax(fmin(base_spacing_x, base_spacing_y), 1);

	// Calcular área total ocupada por la proyección
	double total_projection_width = offset.spacing * grid_size;
	double total_projection_height = offset.spacing * grid_size;

	// Calcular desplazamientos para centrar
	offset.x_offset = (config->width - total_projection_width) / 2.0;
	offset.y_offset = (config->height - total_projection_height) / 2.0;
	return (offset);
}


void	do_points_projection(t_map *map, t_screen_config *config)
{
	t_projection_offset	projection;
	int					i;
	t_point				*c_point;

	projection = calculate_centered_projection(config);
	i = 0;
	while (i < map->cols * map->rows)
	{
		c_point = &map->points[i];
		c_point->x_iso = projection.x_offset + c_point->x_iso * projection.spacing;
		c_point->y_iso = projection.y_offset + c_point->y_iso * projection.spacing;
		i++;
	}
}

void draw_isometric_map(mlx_image_t* image, t_map *map)
{
	int		i;
	t_point	c_point;

	i = 0;
	while (i < map->rows * map->cols)
	{
		c_point = map->points[i];
		if (c_point.x_iso < image->width && c_point.y_iso < image->height) {
			mlx_put_pixel(
				image,
				c_point.x_iso,
				c_point.y_iso,
				c_point.color  // Usar el color del punto original
			);
		}
		if (i < map->rows * map->cols)
		drawline(image, map->points[i], map->points[i + 1]);
		i++;
	}
}

void	render(t_map *map)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_screen_config config = {
		.width = WIDTH,
		.height = HEIGHT,
		.total_points = map->cols * map->rows,
		.padding = 0.1
};

	mlx = mlx_init(config.width, config.height, "FdF", true);
	if (!mlx)
		ft_error("while rendering map");
	img = mlx_new_image(mlx, config.width, config.height);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	do_points_projection(map, &config);
	draw_isometric_map(img, map);
	mlx_image_to_window(mlx, img, 0, 0);
	int i = 0;
	while(i < WIDTH)
	{
		mlx_put_pixel(img, i, (mlx->height / 2), 0xD00F5EFF);
		i++;
	}
	i = 0;
	mlx_loop(mlx);
	mlx_terminate(mlx);
}



int	main(int ac, char **av)
{
	char	*file;
	int		fd;
	t_map	*map;

	if (ac != 2)
		return (1);
	file = av[1];
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Bad file");
	close(fd);
	map = create_map(file);
	if (!map)
		ft_error("While parsing the map");
	//printf("Cols: %d Rows: %d -> %d\n", map->cols, map->rows, (map->cols*map->rows));

	render(map);
	ft_safe_free((void **)&map->points);
	ft_safe_free((void **)&map);
	return (0);
}
