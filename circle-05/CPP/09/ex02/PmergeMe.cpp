#include "PmergeMe.hpp"

bool isValidNumber(const std::string &str, int &val)
{
	int num;
	char extra;
	std::istringstream iss(str);

	if (!(iss >> num) || (iss >> extra))
		return false;
	if (num < 0)
		return false;

	val = num;
	return true;
}

double jacob(int n)
{
	double res;

	if (n == 0 || n == 1)
		return n;

	res = (std::pow(2, n) - std::pow(-1, n)) / 3;

	return res;
}
