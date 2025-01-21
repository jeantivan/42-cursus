/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:45:20 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/21 18:43:18 by jtivan-r         ###   ########.fr       */
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

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_state	*state;

	state = (t_state *)param;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_ESCAPE)
		return (close_hook(param));
}
