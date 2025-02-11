/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:24:19 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/02/11 11:25:16 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_split(char **splited)
{
	int	i;

	i = 0;
	if (!splited)
		return (NULL);
	while (splited[i])
	{
		ft_safe_free((void **)&splited[i]);
		i++;
	}
	return (ft_safe_free((void **)&splited));
}
