/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:07:55 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/04 11:48:52 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_translate(uint32_t key, t_state *state)
{
	float	factor;

	factor = 8.0;
	if (key == MLX_KEY_RIGHT)
		state->map->center[X] = state->map->center[X] + factor;
	else if (key == MLX_KEY_LEFT)
		state->map->center[X] = state->map->center[X] - factor;
	else if (key == MLX_KEY_DOWN)
		state->map->center[Y] = state->map->center[Y] + factor;
	else
		state->map->center[Y] = state->map->center[Y] - factor;
	draw_map(state, false);
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
	{
		if (state->map->scale <= 0)
			return ;
		state->map->scale = (state->map->scale / 1.2) + 0.5;
	}
	else
	{
		if (state->map->scale >= 10000)
			return ;
		state->map->scale = (state->map->scale * 1.2) + 0.5;
	}

	draw_map(state, false);
}

void	handle_rotate(mlx_key_data_t keydata, t_state *state)
{
	int	dir;

	if (keydata.modifier == MLX_CONTROL)
		dir = 1;
	else
		dir = -1;
	if (keydata.key == MLX_KEY_Z)
		state->map->ang[Z] += 1 * dir;
	else if (keydata.key == MLX_KEY_Y)
		state->map->ang[Y] += 1 * dir;
	else if (keydata.key == MLX_KEY_X)
		state->map->ang[X] += 1 * dir;
	draw_map(state, false);
}

void	handle_mode(uint32_t key, t_state *state)
{
	if (key == MLX_KEY_D)
		state->dots = !state->dots;
	else
		state->lines = !state->lines;
	draw_map(state, false);
}
