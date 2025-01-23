/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:45:20 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/23 15:05:29 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_hook(void *param)
{
	t_state	*state;

	state = (t_state *)param;
	if (state->image)
		mlx_delete_image(state->mlx, state->image);
	clean_map(state->map);
	mlx_close_window(state->mlx);
	mlx_terminate(state->mlx);
	ft_safe_free((void **)&state);
	ft_printf("Bye :D\n");
	exit(0);
}

void	handle_translate(uint32_t key, t_state *state)
{
	float	factor;

	factor = 16.0;
	if (key == MLX_KEY_RIGHT)
	{
		state->map->center[X] = state->map->center[X] + factor;
		draw_map(state, false);
	}
	else if (key == MLX_KEY_LEFT)
	{
		state->map->center[X] = state->map->center[X] - factor;
		draw_map(state, false);
	}
	else if (key == MLX_KEY_DOWN)
	{
		state->map->center[Y] = state->map->center[Y] + factor;
		draw_map(state, false);
	}
	else
	{
		state->map->center[Y] = state->map->center[Y] - factor;
		draw_map(state, false);
	}
}

void	handle_reset(t_state *state)
{
	state->map->scale = 1;
	state->map->center[X] = WIN_W / 2;
	state->map->center[Y] = WIN_H / 2;
	state->map->ang[X] = 30;
	state->map->ang[Y] = 330;
	state->map->ang[Z] = 30;
	draw_map(state, true);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_state	*state;

	state = (t_state *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			return (close_hook(param));
		if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
			return (handle_translate(keydata.key, state));
		if (keydata.key == MLX_KEY_R)
			return (handle_reset(state));
	}
}
