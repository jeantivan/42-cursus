/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/20 18:49:51 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

t_state	*init(t_map *map)
{
	t_state		*state;
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIN_W, WIN_H, "FdF - jtivan-r", true);
	if (!mlx)
	{
		clean_map(map);
		ft_error("while rendering map");
	}
	img = mlx_new_image(mlx, WIN_W, WIN_H);
	if (!img)
	{
		clean_map(map);
		mlx_terminate(mlx);
		ft_error("while rendering map");
	}
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	state->mlx = mlx;
	state->image = img;
	state->map = map;
	state->dots = false;
	state->join = true;
	return (state);
}

void	render(t_map *map)
{
	t_state	*state;

	state = init(map);
	draw_map(state, true);
	mlx_image_to_window(state->mlx, state->image, 0, 0);
	mlx_key_hook(state->mlx, &close_hook, NULL);
	mlx_loop(state->mlx);
	mlx_terminate(state->mlx);
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
	map = init_map(map, file);
	if (!map)
		ft_error("While parsing the map");
	printf("WIN_W: %d WIN_H: %d\n\n", WIN_W, WIN_H);
	render(map);
	return (0);
}
