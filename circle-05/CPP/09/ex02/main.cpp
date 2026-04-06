#include "PmergeMe.hpp"
#include <iterator>



int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <numbers...>" << std::endl;
		return 1;
	}

	std::vector<int> vec_numbers;
	std::deque<int> deq_numbers;
	// Insert numbers into vector and deque from command line arguments
	for (int i = 1; i < ac; ++i)
	{
		int num;
		if (!isValidNumber(av[i], num))
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		vec_numbers.push_back(num);
		deq_numbers.push_back(num);
	}

	return 0;
}
