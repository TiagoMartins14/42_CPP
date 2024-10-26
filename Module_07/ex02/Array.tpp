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

	Array(const Array &copy) : _array(NULL), _size(copy._size)
	{
		if (_size > 0)
		{
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		}
	};

	Array &operator=(const Array &copy) {
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
	};

	T &operator[](int index) {
		if (index < 0 || static_cast<size_t>(index) >= _size)
			throw std::out_of_range("Index out of bounds");
		return _array[index];
	}

	~Array() { delete[] _array; };

	size_t size() const { return _size; };
};
