#include "Array.hpp"

template <typename T> Array<T>::Array() {
  _size = 0;
  _array = new T[_size];

  // std::cout << "Empty array created!" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n) {
  _size = n;
  _array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array &copy) : _array(NULL), _size(copy._size) {
  // std::cout << "Copy constructor called" << std::endl;
  if (_size > 0) {
    _array = new T[_size];
    for (size_t i = 0; i < _size; i++)
      _array[i] = copy._array[i];
  }
}

template <typename T> Array<T> &Array<T>::operator=(const Array &copy) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this != &copy) {
    delete[] _array;
    _size = copy._size;
    if (_size > 0) {
      _array = new T[_size];
      for (size_t i = 0; i < _size; i++)
        _array[i] = copy._array[i];
    } else
      _array = NULL;
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](int index) {
  if (index < 0 || static_cast<size_t>(index) >= _size)
    throw std::out_of_range("Index out of bounds");
  return _array[index];
}

template <typename T> Array<T>::~Array() { delete[] _array; }

template <typename T> size_t Array<T>::size() const { return _size; }
