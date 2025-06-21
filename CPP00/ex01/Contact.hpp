#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
  private:
    std::string     _firstName;
    std::string     _lastName;
    std::string     _nickname;
    std::string     _secret;
    std::string     _phoneNumber;
    int             _index;

  public:
    Contact();
    ~Contact();

    bool setContact();
    void savecontact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret, int index);
    void showlittle(void) const;
    void showall(void) const;
    std::string tenchar(std::string test) const;
};

#endif