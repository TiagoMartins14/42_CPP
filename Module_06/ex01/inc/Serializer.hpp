#pragma once
#include "Data.hpp"
#include <stdint.h>

class Serializer {
public:
  Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &copy);
  ~Serializer();

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
