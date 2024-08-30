#include "Array.hpp"

template <typename T> Array<T>::Array() {

  _size = 0;
  _array = new T[_size];
}

template <typename T> Array<T>::Array(unsigned int n) {

  _size = n;
  _array = new T[_size];
}

template <typename T> Array<T>::Array(const Array &copy) {
  if (this != &copy)
    *this = copy;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &copy) {
  this->_size = copy._size;
  this->_array = new T[this->_size];
  for (int i = 0; i < this->_size; i++)
    this->_array[i] = copy._array[i];

  return *this;
}
