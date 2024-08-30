#include "Array.hpp"

template <typename T> Array<T>::Array() {

  _size = 0;
  _array = new T[_size];
}

template <typename T> Array<T>::Array(unsigned int n) {

  _size = n;
  _array = new T[_size];
}
