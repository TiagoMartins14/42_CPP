#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) { *this = other; }

Serializer &Serializer::operator=(const Serializer &copy) {
	(void)copy;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t dataPtr = reinterpret_cast<uintptr_t>(ptr);

	return dataPtr;
}

Data *Serializer::deserialize(uintptr_t raw) {
	Data *rawData = reinterpret_cast<Data *>(raw);

	return rawData;
}
