/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:18:01 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/07 16:34:57 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	*ft_safe_free(void **ptr);
void	ft_free_split(char **splited);
size_t	count_elements(char **inputs);

#endif /* utils.h */