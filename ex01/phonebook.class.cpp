
#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < 8; i++)
		this->_contacts[i].setIndex(i + 1);
}

PhoneBook::~PhoneBook(void){}

std::string	PhoneBook::_fillInfo(std::string const str, int type)
{
	std::string	input;

	while (true)
	{
		std::cout << "Introduce the " << str << " of the contact: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (!input.empty()
				&& check_spaces(input)
				&& ((type == 1 && check_alpha(input))
						|| (type == 2 && check_numbers(input))
						|| !type))
			return trim(input);
		std::cout << std::endl
		<< "Invalid input. Please stick to the format." << std::endl 
		<< std::endl;
	}
}

void	PhoneBook::_displace_contacts(void)
{
	for (int i = 0; i < 7; i++)
	{
		_contacts[i].setFirstName(_contacts[i + 1].getFirstName());
		_contacts[i].setLastName(_contacts[i + 1].getLastName());
		_contacts[i].setNickName(_contacts[i + 1].getNickName());
		_contacts[i].setPhoneNumber(_contacts[i + 1].getPhoneNumber());
		_contacts[i].setDarkestSecret(_contacts[i + 1].getDarkestSecret());
	}
}

void	PhoneBook::addContact(void)
{
	Contact	newContact;
	int		i;
	
	newContact.setFirstName(_fillInfo("first name", 1));
	newContact.setLastName(_fillInfo("last name", 1));
	newContact.setNickName(_fillInfo("nickname", 0));
	newContact.setPhoneNumber(_fillInfo("phone number", 2));
	newContact.setDarkestSecret(_fillInfo("darkest secret", 0));
	i = 0;
	while (i < 8 && !_contacts[i].getFirstName().empty())
		i++;
	
	if (i == 8)
	{
		_displace_contacts();
		i = 7;
	}
	_contacts[i] = newContact;
	for (i = 0; i < 8; i++)
	{
		std::cout << _contacts[i].getFirstName() << std::endl;
		std::cout << _contacts[i].getLastName() << std::endl;
		std::cout << _contacts[i].getNickName() << std::endl;
		std::cout << _contacts[i].getPhoneNumber() << std::endl;
		std::cout << _contacts[i].getDarkestSecret() << std::endl;
	}
}

void	PhoneBook::searchContacts(void) const
{}

