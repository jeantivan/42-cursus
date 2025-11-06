#include <iostream>
#include "FileReplace.hpp"

int main(int ac, char **av)
{
	std::string filename;
	std::string old_str;
	std::string new_str;

	if (ac != 4)
	{
		std::cerr << "Wrong input! Use ./" << av[0] << " \"filename\" \"str_to_replace\" \"new_str\"" << std::endl;
		return (1);
	}

	filename = av[1], old_str = av[2], new_str = av[3];
	FileReplace fileReplace(filename, old_str, new_str);
	fileReplace.replace();
	return (0);
}
