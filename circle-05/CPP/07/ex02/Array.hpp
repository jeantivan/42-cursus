#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
private:
	unsigned int size_;
	T *data_;

public:
	Array();
	Array(unsigned int size);
	Array(const Array &other);
	~Array();
	Array &operator=(const Array &other);
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;


	unsigned int size() const;
};

#include "Array.tpp"

#endif // ARRAY_HPP
