#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
private:
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);
};

#endif // PMERGEME_HPP
