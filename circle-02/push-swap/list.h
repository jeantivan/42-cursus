/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:03:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/07 16:05:41 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	print_list(t_list *list);
t_list	*new_node(int val);

#endif /* list.h */
