#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		// No member variables to copy, but if there were, we would copy them here.
	}
	(void)other;
	return *this;
}

double PmergeMe::jacob(double n) const
{
	double res;

	if (n == 0 || n == 1)
		return n;

	res = (std::pow(2, n) - std::pow(-1, n)) / 3;

	return res;
}
