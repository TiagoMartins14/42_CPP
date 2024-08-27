#include "A.cpp"
#include "B.cpp"
#include "Base.hpp"
#include "C.cpp"
#include "identifyRealType.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void) {
  std::srand(std::time(0));
  int randomNum = std::rand() % 3;

  Base *base = NULL;

  switch (randomNum) {
  case baseA:
    base = new A;
    break;

  case baseB:
    base = new B;
    break;

  case baseC:
    base = new C;
    break;

  default:
    base = NULL;
  }
  return base;
}

void identify(Base *p) {}

void identify(Base &p) {}

int main() { return 0; }
