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

void showVecPairs(std::vector<std::pair<int, int> > vecPairs)
{
	std::cout << "{" << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = vecPairs.begin(); it != vecPairs.end(); it++)
	{
		std::cout << "  [ " << it->first << ", " << it->second << "]" << std::endl;
	}
	std::cout << "}" << std::endl;
}

std::vector<std::pair<int, int> > makeSortedPairs(std::vector<int> numbers)
{
	std::pair<int, int> iPair;
	std::vector<std::pair<int, int> > vec;

	for (size_t i = 0; i < numbers.size(); i += 2)
	{
		if (numbers[i] >= numbers[i + 1])
		{
			iPair.first = numbers[i];
			iPair.second = numbers[i + 1];
		}
		else
		{
			iPair.first = numbers[i + 1];
			iPair.second = numbers[i];
		}
		vec.push_back(iPair);
	}

	return vec;
}

std::vector<int> mergeInsertionSort(std::vector<int> vecToSort)
{

	if (vecToSort.size() == 1)
		return vecToSort;

	bool hasOdd = vecToSort.size() % 2 != 0;
	int oddVal = -1;

	if (hasOdd)
	{
		oddVal = vecToSort.back();
		vecToSort.pop_back();
	}

	std::vector<std::pair<int, int> > pairs = makeSortedPairs(vecToSort);

	// Create winners

	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first);
	}

	// Recursively call mergeInsertionSort on the winners;
	std::vector<int> sorted_winners = mergeInsertionSort(winners);

	// Build main_chain and pend_chain
	std::vector<int> main_chain;
	std::vector<int> pend_chain;

	for (size_t i = 0; i < sorted_winners.size(); i++)
	{
		int curr_winner = sorted_winners[i];
		main_chain.push_back(curr_winner);

		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == curr_winner)
			{
				pend_chain.push_back(pairs[j].second);
				break;
			}
		}
	}

	// Insert first element of pend chain;
	main_chain.insert(main_chain.begin(), pend_chain[0]);

	// TODO: Insert pend_chain inside main_chain following the Jacobsthal numbers;
	// jacob_insert(main_chain, pend_chain);

	if (hasOdd)
	{
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), oddVal);
		main_chain.insert(it, oddVal);
	}

	return main_chain;
}
