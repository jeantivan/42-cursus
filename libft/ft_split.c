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
 * 3- Crear una variable char *temp_s que almacenará la s desplazandose cada vez que se encuentre el delimitador;
 * 4- Crear una función auxiliar que recorra s la cantidad de veces que aparezca el delimitador
 */
char	**ft_split(char const *s, char c)
{

}
