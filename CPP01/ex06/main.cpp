//main.cpp
#include "Harl.hpp"

static int levelIndex(const std::string& s) {
  static const char* names[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
  int i = 0;
  while (i < 4) {
    if (s == names[i]) return i;
    ++i;
  }
  return -1;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return 0;
  }
  Harl h;
  int idx = levelIndex(argv[1]);
  switch (idx) {
    case 0:
      std::cout << "[ DEBUG ]" << std::endl;   h.debug();   std::cout << std::endl;
    case 1:
      std::cout << "[ INFO ]" << std::endl;    h.info();    std::cout << std::endl;
    case 2:
      std::cout << "[ WARNING ]" << std::endl; h.warning(); std::cout << std::endl;
    case 3:
      std::cout << "[ ERROR ]" << std::endl;   h.error();   break;
    default:
      std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  }
  return 0;
}
