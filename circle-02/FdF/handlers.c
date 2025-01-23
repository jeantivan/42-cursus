/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:07:55 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/23 17:21:32 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	handle_scale(double ydelta, t_state *state)
{
	if (ydelta < 0)
		state->map->scale /= 1.2;
	else
		state->map->scale *= 1.2;
	draw_map(state, false);
}

void	handle_rotate(mlx_key_data_t keydata, t_state *state)
{
	if (keydata.key == MLX_KEY_Z)
	{
		if (keydata.modifier == MLX_CONTROL)
			state->map->ang[Z] -= 1;
		else
			state->map->ang[Z] += 1;
	}
	else if (keydata.key == MLX_KEY_W)
		state->map->ang[Y] += 1;
	else if (keydata.key == MLX_KEY_S)
		state->map->ang[Y] -= 1;
	else if (keydata.key == MLX_KEY_A)
		state->map->ang[X] -= 1;
	else
		state->map->ang[X] += 1;
	draw_map(state, false);
}

void	handle_mode(uint32_t key, t_state *state)
{
	if (key == MLX_KEY_P)
		state->dots = !state->dots;
	else
		state->lines = !state->lines;
	draw_map(state, false);
}
