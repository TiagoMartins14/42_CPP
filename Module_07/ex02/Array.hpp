#pragma once
#include <cstdlib>

template <typename T> class Array {
private:
  T *_array;
  size_t _size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &copy);
  Array &operator=(const Array &copy);
  ~Array();

  size_t size() const;
};
