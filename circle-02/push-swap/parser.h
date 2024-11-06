/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:59 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/06 19:06:30 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PARSER_H
# define PARSER_H

# include "libft/libft.h"

int		valid_el(char *el);
t_list	*parse_values(char **argv, size_t size);
int	valid_input(char *input);

#endif /* parser.h */
