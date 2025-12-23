#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <numeric>

class Span
{
private:
	unsigned int N_;
	std::vector<int> numbers_;
public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	~Span();
	Span &operator=(const Span &other);

	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;

	template<typename Iterator>
	void assign(Iterator first, Iterator last) {
		long dist = std::distance(first, last);

		if (numbers_.size() + dist > N_)
		{
			throw std::runtime_error("Not enough space to add elements.");
		}
		numbers_.insert(numbers_.end(), first, last);
	}
};

#endif // SPAN_HPP
