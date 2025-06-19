#include "Contact.hpp"


Contact::Contact(void){
    std::cout << "\033[90mConstructor for Contact called\033[0m" << std::endl;
}

Contact::~Contact(void){
    std::cout << "\033[90mDestructor for Contact called\033[0m" << std::endl;
}

void Contact::savecontact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret, int index)
{
    this->_firstName = firstName;
    this->_lastName = lastName;
    this->_nickname = nickname;
    this->_phoneNumber = phoneNumber;
    this->_secret = secret;
    this->_index = index;
}

std::string Contact::tenchar(std::string test) const
{
    std::string substring;
    std::string to_write;

    if (test.length() > 10) {
        substring = test.substr(0, 9);
        to_write = substring + ".";
    }
    else
        to_write = test;
    return (to_write);
}

void Contact::showlittle(void) const
{
    std::cout << "| " << std::setw(10) << std::right << this->_index << "| "
          << std::setw(10) << std::right << tenchar(this->_firstName) << "| "
          << std::setw(10) << std::right << tenchar(this->_lastName) << "| "
          << std::setw(10) << std::right << tenchar(this->_nickname) << "|\n";
}

void Contact::showall(void) const 
{
    std::cout << "\n ‧͙⁺˚*･༓☾   ☽༓･*˚⁺‧͙ \n" << std::endl;
    std::cout << "- First Name:         " << this->_firstName << std::endl;
    std::cout << "- Last Name:          " << this->_lastName << std::endl;
    std::cout << "- Nick Name:          " << this->_nickname << std::endl;
    std::cout << "- Phone Number:       " << this->_phoneNumber << std::endl;
    std::cout << "- Darkest secret :    " << this->_secret << std::endl;
    std::cout << "\n ‧͙⁺˚*･༓☾   ☽༓･*˚⁺‧͙ \n" << std::endl;
}