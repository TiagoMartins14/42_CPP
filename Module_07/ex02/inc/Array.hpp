#pragma once
#include <cstdlib>
#include <stdexcept>

template <typename T> class Array {
private:
  T *_array;
  size_t _size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &copy);
  Array &operator=(const Array &copy);
  T &operator[](int index);
  ~Array();

  size_t size() const;
};

#include "Array.tpp"
