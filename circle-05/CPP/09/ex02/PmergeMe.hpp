#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <deque>
#include <vector>
#include <cmath>
#include <ctime>
#include <utility>

bool isValidNumber(const std::string &str, int &val);
size_t jacob(int k);
std::vector<int> mergeInsertionSort(std::vector<int> vecToSort);
std::deque<int> mergeInsertionSort(std::deque<int> deqToSort);

template <typename InContainer, typename OutContainer>
void makeSortedPairs(InContainer &numbers, OutContainer &pairs)
{
	typedef typename InContainer::value_type T;

	typename InContainer::iterator it = numbers.begin();

	while (it != numbers.end())
	{
		T first = *it;
		++it;

		if (it == numbers.end())
			break;

		T second = *it;
		++it;

		if (first >= second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}
}

template <typename Container>
void jacobsthalInsert(Container &main_c, Container &pend_c)
{
	// We already inserted pend_c[0] so if size <= 1 there is nothing to insert
	if (pend_c.size() <= 1)
		return;

	size_t pend_size = pend_c.size();
	size_t last_inserted_idx = 0; // Inserted before calling this function

	// We start the Jacobsthal sequence at 3
	size_t prev_j = 1;
	size_t curr_j = 3;

	// Value type of the elements inside the Container;
	typedef typename Container::value_type T;

	while (last_inserted_idx < pend_size - 1)
	{
		// Current index on base 0
		size_t curr_jacob_idx = curr_j - 1;

		// if we pass the size of the container we need to adjust to the last valid index
		if (curr_jacob_idx >= pend_size)
		{
			curr_jacob_idx = pend_size - 1;
		}

		// We insert the current group in reverse order
		for (size_t j = curr_jacob_idx; j > last_inserted_idx; j--)
		{
			T val = pend_c[j];

			typename Container::iterator it = std::lower_bound(main_c.begin(), main_c.end(), val);

			main_c.insert(it, val);
		}

		// Update the starting point for the next group
		last_inserted_idx = curr_jacob_idx;

		// Calculate the next Jacobsthal number
		size_t next_j = curr_j + 2 * prev_j;
		prev_j = curr_j;
		curr_j = next_j;
	}
}

#endif // PMERGEME_HPP
