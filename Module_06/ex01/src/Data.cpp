#include "Data.hpp"

Data::Data(std::string brand, std::string model, int year, int msrp, bool isNew)
    : _brand(brand), _model(model), _year(year), _msrp(msrp), _isNew(isNew) {}

Data::Data(const Data &other) { *this = other; }

Data &Data::operator=(const Data &copy) {
  if (this != &copy) {
    this->_brand = copy._brand;
    this->_model = copy._model;
    this->_year = copy._year;
    this->_msrp = copy._msrp;
    this->_isNew = copy._isNew;
  }
  return *this;
}
Data::~Data() {}
