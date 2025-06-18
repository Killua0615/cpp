#include <iostream>

int main(int ac, char **av)
{
  int wd = 1;

  if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
  {
    while (wd < ac)
    {
      int i = 0;
      while (av[wd][i])
      {
        std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(av[wd][i])));
        i++;
      }
      wd++;
    }
  }
  std::cout << std::endl;
}