#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename S>
void iter(T *arr, const S size, void (*func)(T &))
{
	if (!arr)
		return;
	for (S i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

template <typename T, typename S>
void iter(const T *arr, const S size, void (*func)(const T &))
{
	if (!arr)
		return;
	for (S i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

template <typename T>
void show(const T &el)
{
	std::cout << el << std::endl;
}
template <typename T>
void power2(T &n)
{
	n *= n;
}

struct Awesome {
	int id;
	std::string name;
};

#endif // ITER_HPP
