#include "Contact.hpp"

bool Contact::setContact()
{
	std::cout << "First name     : ";
	std::getline(std::cin, this->_firstName);
	if (this->_firstName.empty())
		return (false);
	std::cout << "Last name      : ";
	std::getline(std::cin, this->_lastName);
	if (this->_lastName.empty())
		return (false);
	std::cout << "Nickname       : ";
	std::getline(std::cin, this->_nickname);
	if (this->_nickname.empty())
		return (false);
	std::cout << "Phone number   : ";
	std::getline(std::cin, this->_phoneNumber);
	if (this->_phoneNumber.empty())
		return (false);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, this->_secret);
	if (this->_secret.empty())
		return (false);
	return (true);
}

Contact::Contact(void)
{
	std::cout << "\033[90mConstructor for Contact called\033[0m" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "\033[90mDestructor for Contact called\033[0m" << std::endl;
}

void Contact::savecontact(std::string firstName, std::string lastName,
	std::string nickname, std::string phoneNumber, std::string secret,
	int index)
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

	if (test.length() > 10)
	{
		substring = test.substr(0, 9);
		to_write = substring + ".";
	}
	else
		to_write = test;
	return (to_write);
}

void Contact::showlittle(void) const
{
	std::cout << "| " << std::setw(10) << std::right << this->_index << "| " << std::setw(10) << std::right << tenchar(this->_firstName) << "| " << std::setw(10) << std::right << tenchar(this->_lastName) << "| " << std::setw(10) << std::right << tenchar(this->_nickname) << "|\n";
}

void Contact::showall(void) const
{
	std::cout << "----------------------------" << std::endl;
	std::cout << "- First name          :" << this->_firstName << std::endl;
	std::cout << "- Last name           :" << this->_lastName << std::endl;
	std::cout << "- Nickname            :" << this->_nickname << std::endl;
	std::cout << "- Phone Number:       :" << this->_phoneNumber << std::endl;
	std::cout << "- Darkest secret      :" << this->_secret << std::endl;
	std::cout << "----------------------------" << std::endl;
}