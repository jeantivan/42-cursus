#include "PmergeMe.hpp"
#include <iterator>
#include <iomanip>

double expensive_func()
{
	double sum = 0;
	double add = 1;
	int iterations = 1000 * 1000 * 100;
	for (int i = 0; i < iterations; i++)
	{
		sum += add;
		add /= 2.0;
	}
	return sum;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <numbers...>" << std::endl;
		return 1;
	}

	std::vector<int> vec_numbers;
	// std::deque<int> deq_numbers;
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
		// deq_numbers.push_back(num);
	}
	int oddNum;
	bool hasOdd = vec_numbers.size() % 2 != 0;
	if (hasOdd)
	{
		oddNum = *(vec_numbers.end() - 1);
		vec_numbers.pop_back();
	}

	std::vector<std::pair<int, int> > vecPairs = makeSortedPairs(vec_numbers);
	showVecPairs(vecPairs);
	if (oddNum)
		std::cout << "Odd num " << oddNum << std::endl;
	return 0;
}
