
#include "phonebook.hpp"

PhoneBook::PhoneBook(void){}

PhoneBook::~PhoneBook(void){}

std::string	PhoneBook::_fillInfo(std::string const str, int type)
{
	std::string	input;

	while (true)
	{
		std::cout << G << "Please, introduce the " << str << " of the contact: " << RS;
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (!input.empty()
				&& check_spaces(input)
				&& ((type == 1 && check_alpha(input))
						|| (type == 2 && check_phone(input))
						|| !type))
			return trim(input);
		std::cout << std::endl
		<< R << "Invalid input. Please stick to the format." << RS << std::endl 
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
	long long	index;

	index = 0;
	while (true)
	{
		std::cout << std::endl << G
			<< "Introduce the index of the contact to display information: " << RS;
		std::getline(std::cin, input);
		if (!input.empty() && check_spaces(input))
		{
			input = trim(input);
			if (check_digits(input) && input.length() < 19)
			{
				index = std::stoll(input);
				if (index < std::numeric_limits<int>::min()
					|| index > std::numeric_limits<int>::max())
					index = 0;
			}
		}
		if (index > 0 && index < 9 && !_contacts[index - 1].getFirstName().empty())
			break ;
		std::cout << R << std::endl << "Invalid index" << RS << std::endl;
		index = 0;
	}
	std::cout << C << std::endl << "Contact " << index << ":" << std::endl;
	index--;
	std::cout << Y << "\tFirst name: " << RS << _contacts[index].getFirstName() << std::endl
		<< Y << "\tLast name: " << RS << _contacts[index].getLastName() << std::endl
		<< Y << "\tNickame: " << RS << _contacts[index].getNickName() << std::endl
		<< Y << "\tPhone number: " << RS << _contacts[index].getPhoneNumber() << std::endl
		<< Y << "\tDarkest secret: " << RS << _contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContacts(void) const
{
	int	i;

	i = 0;
	if (_contacts[i].getFirstName().empty())
	{
		std::cout << R << "The PhoneBook is empty" << RS << std::endl;
		return ;
	}
	std::cout << M << " ___________________________________________" << std::endl
		<< "|" << G << std::setw(10) << std::left << "Index" << M << "|"
    	<< G << std::setw(10) << std::left << "First Name" << M << "|"
    	<< G << std::setw(10) << std::left << "Last Name" << M << "|"
    	<< G << std::setw(10) << std::left << "Nickname" << M << "|"
    	<< std::endl
    	<< "|----------|----------|----------|----------|" << std::endl;
	while (i < 8 && !_contacts[i].getFirstName().empty())
	{
		std::cout << "|" << Y << std::setw(10) << std::right << i + 1
			<< M << "|" << C << std::setw(10) << std::right << _truncateInfo(_contacts[i].getFirstName())
			<< M << "|" << C << std::setw(10) << std::right << _truncateInfo(_contacts[i].getLastName())
			<< M "|" << C << std::setw(10) << std::right << _truncateInfo(_contacts[i].getNickName())
			<< M << "|" << std::endl;
		i++;
	}
	std::cout << "|__________|__________|__________|__________|" << RS << std::endl;
	_promptAndDisplay();
}
