#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;

}


template<typename T>
T min(T a, T b)
{
	if (a > b)
		return b;
	return a;
}

template<typename T>
T max(T a, T b)
{
	if (a < b)
		return b;
	return a;
}

#endif // TEMPLATE_HPP
