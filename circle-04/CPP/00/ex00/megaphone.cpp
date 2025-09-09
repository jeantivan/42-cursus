#include <iostream>

int main(int ac, char **av)
{

	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
	{
		int i = 1, j;
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << (char)std::toupper(av[i][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}

