/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:45:20 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/03 17:24:19 by jtivan-r         ###   ########.fr       */
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

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_state	*state;

	state = (t_state *)param;
	return (handle_scale(ydelta, state));
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_state	*state;

	state = (t_state *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (close_hook(param));
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
			return (handle_reset(state));
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_L) \
		&& keydata.action == MLX_PRESS)
			return (handle_mode(keydata.key, state));
		if ((keydata.key == MLX_KEY_P || keydata.key == MLX_KEY_I) \
		&& keydata.action == MLX_PRESS)
			return (handle_view(keydata.key, state));
		if (keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP)
			return (handle_translate(keydata.key, state));
		if (keydata.key == MLX_KEY_X || keydata.key == MLX_KEY_Y \
		|| keydata.key == MLX_KEY_Z)
			return (handle_rotate(keydata, state));
	}
}
