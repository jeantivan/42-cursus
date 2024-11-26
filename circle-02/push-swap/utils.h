/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:18:01 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/26 19:03:04 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void		*ft_safe_free(void **ptr);
void		*ft_free_split(char **splited);
int			arr_length(char **arr);
long int	ft_atol(char *ptr);

#endif /* utils.h */
