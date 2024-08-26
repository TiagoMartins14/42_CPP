#pragma once
#include <string>

class Data {
private:
  std::string _brand;
  std::string _model;
  int _year;
  int _msrp;
  bool _isNew;

public:
  Data(std::string brand, std::string model, int year, int msrp, bool isNew);
  Data(const Data &other);
  Data &operator=(const Data &copy);
  ~Data();

  std::string getBrand();
  std::string getModel();
  int getYear();
  int getMsrp();
  bool getIsNew();

  void setMsrp(int msrpValue);
};
