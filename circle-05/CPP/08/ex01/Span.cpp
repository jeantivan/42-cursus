#include "Span.hpp"

Span::Span() : N_(0), numbers_(std::vector<int>()) {}

Span::Span(unsigned int n) : N_(n), numbers_(std::vector<int>()) {}

Span::~Span() {}

Span::Span(const Span &other) : N_(other.N_), numbers_(other.numbers_) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N_ = other.N_;
		numbers_ = other.numbers_;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (numbers_.size() == N_)
		throw std::runtime_error("Max size reached.");
	numbers_.push_back(num);
}

unsigned int Span::shortestSpan() const
{
	if (numbers_.empty() || numbers_.size() == 1)
		throw std::runtime_error("Impossible to get a span, vector too small.");

	std::vector<int> copy = numbers_;
	std::vector<int> result(copy.size());

	// C++ generally uses Introsort (Introspective Sort), a hybrid algorithm that guarantees a time complexity of O( N · log(N) )
	std::sort(copy.begin(), copy.end());
	std::adjacent_difference(copy.begin(), copy.end(), result.begin());
	std::vector<int>::const_iterator min_el = std::min_element(result.begin() + 1, result.end());
	return static_cast<unsigned int>(*min_el);
}

unsigned int Span::longestSpan() const
{
	if (numbers_.empty() || numbers_.size() == 1)
		throw std::runtime_error("Impossible to get a span, vector too small.");

	std::vector<int>::const_iterator min_el = std::min_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator max_el = std::max_element(numbers_.begin(), numbers_.end());

	return static_cast<unsigned int>(*max_el) - static_cast<unsigned int>(*min_el);
}
