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

/**
 * En caso de que no se pueda asignar memoria en algún momento
 * se limpia la memoria que ya pudo haber sido asignada
 */
static void	ft_free_memory(char **arr)
{
	int	i;

	i = 0;
	while (arr[i++])
		free(arr[i]);
	free(arr);
}

/**
 * Se encuentran las cantidad de elementos (palabras)
 * que tendrá nuestro arreglo final.
 */
static int	ft_find_n_of_el(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static char	**ft_save_str_pieces(const char *s, char c, char **arr)
{
	int	pace;
	int	i;
	int	start;

	pace = 0;
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			arr[pace++] = ft_substr(s, start, i - start + 1);
			if (!arr[pace - 1])
			{
				ft_free_memory(arr);
				return (NULL);
			}
		}
		if (s[i] == c && (s[i + 1] != c || s[i + 1] != '\0'))
			start = i + 1;
		i++;
	}
	arr[pace] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		n_of_el;
	char	**arr;

	n_of_el = ft_find_n_of_el(s, c);
	arr = (char **)malloc((n_of_el + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = ft_save_str_pieces(s, c, arr);
	return (arr);
}
