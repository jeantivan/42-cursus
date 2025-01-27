/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:46:53 by jtivan-r          #+#    #+#             */
/*   Updated: 2024/09/17 12:46:56 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}
/*

int	main(void)
{
	printf("Original isalpha\n");
	printf("A is alpha: %d\n", isalpha('A'));
	printf("B is alpha: %d\n", isalpha('B'));
	printf("a is alpha: %d\n", isalpha('a'));
	printf("c is alpha: %d\n", isalpha('c'));
	printf("r is alpha: %d\n", isalpha('r'));
	printf("T is alpha: %d\n", isalpha('T'));

	printf("2 is alpha: %d\n", isalpha('2'));
	printf("3 is alpha: %d\n", isalpha('3'));
	printf("5 is alpha: %d\n", isalpha('5'));
	printf("9 is alpha: %d\n", isalpha('9'));
	printf("1 is alpha: %d\n", isalpha('1'));
	printf("0 is alpha: %d\n", isalpha('0'));


	printf("\nMy ft_isalpha\n");
	printf("B is alpha: %d\n", ft_isalpha('B'));
	printf("a is alpha: %d\n", ft_isalpha('a'));
	printf("c is alpha: %d\n", ft_isalpha('c'));
	printf("r is alpha: %d\n", ft_isalpha('r'));
	printf("T is alpha: %d\n", ft_isalpha('T'));

	printf("2 is alpha: %d\n", ft_isalpha('2'));
	printf("3 is alpha: %d\n", ft_isalpha('3'));
	printf("5 is alpha: %d\n", ft_isalpha('5'));
	printf("1 is alpha: %d\n", ft_isalpha('9'));
	printf("4 is alpha: %d\n", ft_isalpha('1'));
	printf("0 is alpha: %d\n", ft_isalpha('0'));

	printf("\nMore test\n");
	printf("1 int is alpha: %d\n", ft_isalpha(1));
	printf("42 int is alpha: %d\n", ft_isalpha(42));
	printf("-1 int is alpha: %d\n", ft_isalpha(-1));
	printf("42000 int is alpha: %d\n", ft_isalpha(42000));
	printf("-42000 int is alpha: %d\n", ft_isalpha(-42000));
	printf("4200000000000 int is alpha: %d\n", ft_isalpha(4200000000000));
	printf("4200000000000 int is alpha: %d\n", ft_isalpha(-4200000000000));

	printf("\n\n\n");
	printf("1 int is alpha: %d\n", isalpha(1));
	printf("42 int is alpha: %d\n", isalpha(42));
	printf("-1 int is alpha: %d\n", isalpha(-1));
	printf("42000 int is alpha: %d\n", isalpha(42000));
	printf("-42000 int is alpha: %d\n", isalpha(-42000));
	printf("420000000 int is alpha: %d\n", isalpha(420000000));
	printf("420000000 int is alpha: %d\n", isalpha(-420000000));
	return (0);
} */
