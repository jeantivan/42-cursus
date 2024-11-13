/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:59 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/11/13 18:13:06 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft/libft.h"

int		valid_el(char *el);
t_list	*parse_values(char **argv, int argc);
int		valid_input(char *input);

#endif /* parser.h */
