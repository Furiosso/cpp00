
#include "phonebook.hpp"

PhoneBook::PhoneBook(void){}

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
						|| (type == 2 && check_phone(input))
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
}

std::string	PhoneBook::_truncateInfo(std::string str) const
{
	int			len;
	std::string	copy;

	len = str.length();
	copy = str;
	if (len > 10)
	{
		copy[9] = '.';
		if (copy[10])
		{
			while (--len > 9)
				copy[len] = '\0';
		}
	}
	return copy;
}

void	PhoneBook::_promptAndDisplay(void) const
{
	std::string	input;
	int			index;

	index = 0;
	while (true)
	{
		std::cout << "Introduce index of the contact to display information: ";
		std::getline(std::cin, input);
		if (!input.empty() && check_digits(input))
			index = std::stoi(input);
		if (index > 0 && index < 9 && !_contacts[index - 1].getFirstName().empty())
			break ;
		std::cout << std::endl << "Invalid index." << std::endl;
		index = 0;
	}
	std::cout << std::endl << "Contact " << index << ":" << std::endl;
	index--;
	std::cout << "\tFist name: " << _contacts[index].getFirstName() << std::endl
		<< "\tLast name: " << _contacts[index].getLastName() << std::endl
		<< "\tNickame: " << _contacts[index].getNickName() << std::endl
		<< "\tPhone number: " << _contacts[index].getPhoneNumber() << std::endl
		<< "\tDarkest secret: " << _contacts[index].getDarkestSecret() << std::endl
		<< std::endl;
}


void	PhoneBook::searchContacts(void) const
{
	int	i;

	i = 0;
	if (_contacts[i].getFirstName().empty())
	{
		std::cout << "The PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << "|";
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << "|";
    std::cout << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < 8 && !_contacts[i].getFirstName().empty())
	{
		std::cout << "|" << std::setw(10) << std::right << i + 1
			<< "|" << std::setw(10) << std::right << _truncateInfo(_contacts[i].getFirstName())
			<< "|" << std::setw(10) << std::right << _truncateInfo(_contacts[i].getLastName())
			<< "|" << std::setw(10) << std::right << _truncateInfo(_contacts[i].getNickName())
			<< "|" << std::endl;
		i++;
	}
	_promptAndDisplay();
}
