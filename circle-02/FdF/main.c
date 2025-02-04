/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:36:52 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/04 18:59:41 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <time.h>

t_state	*init(t_map *map)
{
	t_state	*s;

	s = (t_state *)malloc(sizeof(t_state));
	if (!s)
	{
		clean_map(map);
		ft_error("Failed to allocate memory");
		return (NULL);
	}
	s->map = map;
	s->dots = false;
	s->lines = true;
	s->mlx = mlx_init(WIN_W, WIN_H, "FdF - jtivan-r", true);
	if (!s->mlx)
		return (clean_with_error(s, "Failed to allocate memory"));
	s->image = mlx_new_image(s->mlx, WIN_W, WIN_H);
	if (!s->image)
		return (clean_with_error(s, "Failed to allocate memory"));
	return (s);
}

void	render(t_map *map)
{
	t_state	*state;

	state = init(map);
	draw_map(state, true);
	mlx_image_to_window(state->mlx, state->image, 0, 0);
	mlx_close_hook(state->mlx, &close_hook, state);
	mlx_key_hook(state->mlx, &key_hook, state);
	mlx_scroll_hook(state->mlx, &scroll_hook, state);
	mlx_loop(state->mlx);
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
	map = init_map(file);
	if (!map)
		ft_error("While parsing the map");
	ft_printf("WIN_W: %d WIN_H: %d\n\n", WIN_W, WIN_H);
	render(map);
	return (0);
}
