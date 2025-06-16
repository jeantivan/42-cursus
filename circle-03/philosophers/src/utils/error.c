/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:50:33 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/06/16 12:25:45 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_puterror(char *str, char *info)
{
	ft_putstr_fd(BGR"🚨 Error: "RST, 2);
	ft_putstr_fd(R" ", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd(RST, 2);
	if (info)
	{
		ft_putstr_fd(BGY"🔎 Info: "RST, 2);
		ft_putstr_fd(Y" ", 2);
		ft_putendl_fd(info, 2);
		ft_putstr_fd(RST, 2);
	}
	return (EXIT_FAILURE);
}
