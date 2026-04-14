#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <deque>
#include <vector>
#include <cmath>
#include <ctime>

bool isValidNumber(const std::string &str, int &val);
size_t jacob(int k);

template <typename Func>
double measure_time(Func f)
{
	std::time_t start, end;

	time(&start);

	f();

	time(&end);

	return double(end - start);
}
std::vector<std::pair<int, int> > makeSortedPairs(std::vector<int> &numbers);
void showVecPairs(std::vector<std::pair<int, int> > &vecPairs);
std::vector<int> mergeInsertionSort(std::vector<int> &vecToSort);

#endif // PMERGEME_HPP
