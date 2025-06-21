#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <limits>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int ask_index(PhoneBook &directory)
{
  int index;

  while (true) 
  {
    std::cin >> index;
    std::cin.ignore(1000, '\n');

    if (std::cin.fail()) 
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "\033[31mGive me a valid integer!\033[0m" << std::endl;
    }
    else if (index < 0 || index > 7 || index > directory.getfull()) {
      std::cout << "\033[31m> Invalid index.\033[0m" << std::endl << std::endl;
      return -1;
    }
    else
      break;
  }
  return index;
}

void search(PhoneBook &directory)
{
  int index;
    
  (void) index;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "|   Index   | First Name | Last Name| Nick Name |" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  directory.show_directory();
  if (directory.getsize() == 0) {
    std::cout << "\033[31mDirectory seems empty!\033[0m\n\n";
    return ;
  }
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "\n";
  std::cout << "\033[34m> Enter a valid index of the contact to view details.\033[0m" << std::endl;
  index = ask_index(directory);
  if (index >= 0)
    directory.show_contact(index);
}

void add(PhoneBook &directory)
{
  std::cout << "\033[34mGet me some information!\033[0m" << std::endl;

  if (!directory.add_repertory())
    return;
}

int main()
{
  std::string action;
    
  PhoneBook directory(0);

  std::cout << "\e[1;1H\e[2J";
  std::cout << "\033[34m  🌊 Welcome to my PhoneBook 🌊 \033[0m" << std::endl;
  while (1)
  {
    std::cout << "> Command (SEARCH, ADD, EXIT)" << std::endl;
    if (!std::getline(std::cin, action))
    {
      if (std::cin.eof())
        break;
    }
    std::cout << std::endl;
    if (action == "ADD")
      add(directory);
    else if (action == "SEARCH")
      search(directory);
    else if (action == "EXIT")
    {
      std::cout << "\033[34mThank you for using.\033[0m" << std::endl;
      break;
    }
    else
      std::cout << "\033[31m> Unknown command.\033[0m" << std::endl;
  }
  return (0);
}