/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:01:49 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/12/10 20:02:28 by jtivan-r         ###   ########.fr       */
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
