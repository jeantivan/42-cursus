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

size_t jacob(int n)
{
	if (n == 0 || n == 1)
		return n;

	size_t prev2 = 0; // J(n-2)
	size_t prev1 = 1; // J(n-1)
	size_t curr = 0;

	// J(n) = J(n - 1) + 2 * J (n - 2) -> n > 1;
	for (int i = 2; i <= n; i++)
	{
		curr = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = curr;
	}

	return curr;
}

void showVecPairs(std::vector<std::pair<int, int> > &vecPairs)
{
	std::cout << "{" << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it = vecPairs.begin(); it != vecPairs.end(); it++)
	{
		std::cout << "  [ " << it->first << ", " << it->second << "]" << std::endl;
	}
	std::cout << "}" << std::endl;
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

	std::vector<std::pair<int, int> > pairs;
	makeSortedPairs(vecToSort, pairs);

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

	// Insert the pend chain inside main chain following the Jacobsthal numbers
	jacobsthalInsert(main_chain, pend_chain);

	// If we had a odd size we insert the last element.
	if (hasOdd)
	{
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), oddVal);
		main_chain.insert(it, oddVal);
	}

	return main_chain;
}

std::deque<int> mergeInsertionSort(std::deque<int> deqToSort)
{

	if (deqToSort.size() == 1)
		return deqToSort;

	bool hasOdd = deqToSort.size() % 2 != 0;
	int oddVal = -1;

	if (hasOdd)
	{
		oddVal = deqToSort.back();
		deqToSort.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	makeSortedPairs(deqToSort, pairs);

	// Create winners
	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first);
	}

	// Recursively call mergeInsertionSort on the winners;
	std::deque<int> sorted_winners = mergeInsertionSort(winners);

	// Build main_chain and pend_chain
	std::deque<int> main_chain;
	std::deque<int> pend_chain;

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

	// Insert the pend chain inside main chain following the Jacobsthal numbers
	jacobsthalInsert(main_chain, pend_chain);

	// If we had a odd size we insert the last element.
	if (hasOdd)
	{
		std::deque<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), oddVal);
		main_chain.insert(it, oddVal);
	}

	return main_chain;
}
