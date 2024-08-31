#pragma once
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
   private:
	T *_array;
	size_t _size;

   public:
	Array() : _array(NULL), _size(0){};

	Array(unsigned int n) {
		_size = n;
		_array = new T[_size];
	};

	Array(const Array &copy) { *this = copy; };

	Array &operator=(const Array &copy) {
		if (this != &copy) {
			delete[] this->_array;
			this->_size = copy._size;
			if (this->_size > 0) {
				this->_array = new T[this->_size];
				for (size_t i = 0; i < this->_size; i++)
					this->_array[i] = copy._array[i];
			} else
				this->_array = NULL;
		}

		return *this;
	};

	T &operator[](int index) {
		if (index < 0 || static_cast<size_t>(index) >= _size)
			throw std::out_of_range("Index out of bounds");
		return _array[index];
	}

	~Array() { delete[] _array; };

	size_t size() const { return _size; };
};
