#pragma once
#include <cstdlib>

template <typename T> class Array {
private:
  T *_array;
  size_t _size;

public:
  Array() {

    _size = 0;
    _array = new T[_size];
  };

  Array(unsigned int n) {

    _size = n;
    _array = new T[_size];
  };

  Array(const Array &copy) { *this = copy; };

  Array &operator=(const Array &copy) {
    if (this != &copy) {
      this->_size = copy._size;
      this->_array = new T[this->_size];
      for (int i = 0; i < this->_size; i++)
        this->_array[i] = copy._array[i];
    }

    return *this;
  };

  ~Array() {
    if (_array)
      delete[] _array;
  };

  size_t size() const { return _size; };
};
