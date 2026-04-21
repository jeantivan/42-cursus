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

	// Vars to measure the time
	std::clock_t vt_start, vt_end, dt_start, dt_end;

	// Containers for the test
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
	std::cout << "Size " << vec_numbers.size() << " " << deq_numbers.size() << " Before: ";
	for (size_t i = 0; i < vec_numbers.size(); i++)
	{
		// if (i <= 15)
		std::cout << vec_numbers[i] << " ";
		// if (i == 16)
		// 	std::cout << "...";
	}
	std::cout << std::endl;

	// Time to sort using std::vector
	vt_start = std::clock();
	std::vector<int> sorted_vec_numbers = mergeInsertionSort(vec_numbers);
	vt_end = std::clock();

	// Time to sort using std::deque
	dt_start = std::clock();
	std::deque<int> sorted_deq_numbers = mergeInsertionSort(deq_numbers);
	dt_end = std::clock();

	double vec_time = 1000.0 * double(vt_end - vt_start) / CLOCKS_PER_SEC;
	double deq_time = 1000.0 * double(dt_end - dt_start) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	for (size_t i = 0; i < sorted_vec_numbers.size(); i++)
	{
		// if (i <= 15)
		std::cout << sorted_vec_numbers[i] << " ";
		// if (i == 16)
		// 	std::cout << "...";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << sorted_vec_numbers.size() << " with std::vector : " << std::fixed << std::setprecision(8) << vec_time << " ms" << std::endl;
	std::cout << "Time to process a range of " << sorted_deq_numbers.size() << " with std::deque : " << std::fixed << std::setprecision(8) << deq_time << " ms" << std::endl;
	return 0;
}
