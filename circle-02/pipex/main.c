/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:09:21 by jtivan-r          #+#    #+#             */
/*   Updated: 2025/01/29 14:46:46 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char	*cmd_path1;
	char	*cmd_path2;

	// TODO: Gestionar cantidad correcta de argumentos
	if (ac == 1 || ac != 5)
		return (EXIT_FAILURE);
	cmd_path1 = find_cmd_abs_path(av[2], env);
	if (!cmd_path1)
	{
		ft_printf("%s: Command could not be found.\n", av[2]);
		exit(EXIT_FAILURE);
	}
	cmd_path2 = find_cmd_abs_path(av[3], env);
	if (!cmd_path2)
	{
		ft_printf("%s: Command could not be found.\n", av[2]);
		ft_safe_free((void **)&cmd_path1);
		exit(EXIT_FAILURE);
	}
	ft_printf("%s\n", cmd_path1);
	ft_printf("%s\n", cmd_path2);
	ft_safe_free((void **)&cmd_path1);
	ft_safe_free((void **)&cmd_path2);
	return (0);
}
