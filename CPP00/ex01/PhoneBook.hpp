#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
    int _size;
    static const int MAX_CONTACTS = 8;
    int _full;

    Contact _contacts[MAX_CONTACTS];
        
  public:
    PhoneBook(int size);
    ~PhoneBook();

    bool add_repertory();
    void add_repertory(std::string firstName, std::string lastName, std::string nickname, std::string secret, std::string phoneNumber);
    void show_directory(void) const;
    void show_contact(int index) const;
    int getsize(void);
    void setsize(void);
    int getfull(void);
    void setfull(void);
};

#endif