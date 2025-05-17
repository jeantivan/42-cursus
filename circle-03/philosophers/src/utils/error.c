/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:50:33 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/05/17 22:06:22 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_puterror(char *str, char *info)
{
	ft_putstr_fd(BGRED"🚨 Error: "RST, 2);
	ft_putstr_fd(RED" ", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(RST, 2);
	if (info)
	{
		ft_putstr_fd(BGYELLOW"🔎 Info: "RST, 2);
		ft_putstr_fd(YELLOW" ", 2);
		ft_putendl_fd(info, 2);
		ft_putstr_fd(RST, 2);
	}
	return (EXIT_FAILURE);
}
