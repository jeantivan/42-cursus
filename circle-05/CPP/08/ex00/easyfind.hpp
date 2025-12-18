#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, const int& to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end())
		return it;
	throw std::runtime_error("Error: Value not found!");
}

template<typename T>
typename T::const_iterator easyfind(const T &container, const int& to_find) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end())
		return it;
	throw std::runtime_error("Error: Value not found!");
}
#endif // EASYFIND_HPP
