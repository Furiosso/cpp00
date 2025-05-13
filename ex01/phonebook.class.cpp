
#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < 8; i++)
		this->_contacts[i].setIndex(i + 1);
}

PhoneBook::~PhoneBook(void){}

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
	_contacts[7].setFirstName("");
	_contacts[7].setLastName("");
	_contacts[7].setNickName("");
	_contacts[7].setPhoneNumber("");
	_contacts[7].setDarkestSecret("");
}

void	PhoneBook::addContact(void)
{
	std::string	input;
	Contact		newContact;
	int			i;

	while (true)
	{
		std::cout << "Introduce the first name of the contact: ";
		std::getline(std::cin, input);
		if (!input.empty() && check_spaces(input) && check_alpha(input))
		{
			newContact.setFirstName(input);
			break ;
		}
		std::cout << std::endl
		<< "Invalid input. Please stick to the format." << std::endl
		<< std::endl
		<< "Only alphabetic characters allowed," << std::endl 
		<< "spaces are forbidden in the beggining and the end of the name" << std::endl
		<< "and there cannot be two spaces in a row." << std::endl;
	}

	i = 0;
	while (!_contacts[i].getFirstName().empty() && i < 8)
		i++;
	
	if (i == 8)
	{
		_displace_contacts();
		i = 7;
	}

	_contacts[i] = newContact;
	std::cout << _contacts[i].getFirstName() << std::endl;
}
