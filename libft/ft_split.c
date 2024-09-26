/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:54:41 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/25 18:54:44 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/**
 * Función ft_split
 *
 * Descripción:
 *		Reserva (utilizando malloc(3)) un array de strings
 *		resultante de separar la string ’s’ en substrings
 *		utilizando el caracter ’c’ como delimitador. El
 *		array debe terminar con un puntero NULL.
 *
 * Input:
 *	s = "Lorem.ipsum.dolor.sit.amet.consectetur"
 *	c = '.'
 * Output:
 * 	char **r = {"Lorem", "ipsum", "dolor", "sit", "amet", "consectetur"}
 */

/**
 * Algoritmo:
 *
 * 1- Recorrer s y contar las apariciones del delimitador c -> (int n_of_c)
 * 2- Alocar la memoria para el array de string -> (n + 1) * sizeof(char *)
 * 3- Crear una variable char *temp_s que almacenará la s
 *    desplazandose cada vez que se encuentre el delimitador;
 * 4- Crear una función auxiliar que recorra s la cantidad de veces
 *    que aparezca el delimitador
 */
static int	ft_find_n_of_c(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

static char	*ft_get_str_piece(char *temp_s, char c)
{
	int		len;
	char	*piece;

	len = 0;
	while (temp_s[len] != c)
		len++;
	piece = ft_substr(temp_s, 0, len);
	return (piece);
}

char	**ft_split(char const *s, char c)
{
	int		n_of_c;
	int		pace;
	char	**arr;
	char	*temp_s;

	n_of_c = ft_find_n_of_c(s, c);
	arr = (char **)malloc((n_of_c + 2) * sizeof(char *));
	if (!arr)
		return (NULL);
	temp_s = (char *)s;
	pace = 0;
	while (pace <= n_of_c)
	{
		while (*temp_s != '\0')
		{
			if (temp_s[0] == c && temp_s[1] != c && temp_s[1] != '\0')
			{
				arr[pace] = ft_get_str_piece(temp_s + 1, c);
				temp_s = temp_s + ft_strlen(arr[pace]) + 1;
				break ;
			}
			else if (temp_s[0] != c && temp_s[1] != '\0')
			{
				arr[pace] = ft_get_str_piece(temp_s, c);
				temp_s = temp_s + ft_strlen(arr[pace]);
				break ;
			}
			temp_s++;
		}
		pace++;
	}
	arr[pace] = NULL;
	return (arr);
}
