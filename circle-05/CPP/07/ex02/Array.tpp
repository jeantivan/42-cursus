#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stdexcept>

template<typename T>
Array<T>::Array() : size_(0), data_(NULL) {

}

template<typename T>
Array<T>::Array(unsigned int size) : size_(size), data_(new T[size]()) {

}

template<typename T>
Array<T>::~Array() {
	delete []data_;
}

template<typename T>
Array<T>::Array(const Array<T>& other) : size_(other.size_), data_(NULL) {
	if (size_ > 0)
	{
		data_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++) {
			data_[i] = other.data_[i];
		}
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] data_;

		size_ = other.size_;

		if (size_ > 0) {

			data_ = new T[size_];

			for(unsigned int i = 0; i < size_; i++)
				data_[i] = other.data_[i];
		} else
			data_ = NULL;
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= size_ || data_ == NULL)
		throw std::out_of_range("Index out of range");
	return data_[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= size_ || data_ == NULL)
		throw std::out_of_range("Index out of range");
	return data_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return size_;
}

#endif // ARRAY_TPP
