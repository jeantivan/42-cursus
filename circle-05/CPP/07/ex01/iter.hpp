#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename S, typename F>
void iter(T arr, const S size, F func)
{
	if (!arr || !func)
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

#endif // ITER_HPP
