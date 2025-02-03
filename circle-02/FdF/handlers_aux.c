/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:20:04 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/03 18:56:55 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_view(uint32_t key, t_state *state)
{
	if (key == MLX_KEY_P)
	{
		state->map->ang[Y] = 0;
		state->map->ang[X] = 90;
		state->map->ang[Z] = 0;
	}
	else
	{
		state->map->ang[X] = 30;
		state->map->ang[Y] = 330;
		state->map->ang[Z] = 30;
	}
	draw_map(state, false);
}
