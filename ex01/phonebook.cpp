#include "phonebook.hpp"

bool	check_spaces(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isspace(str[i]))
			return true;
		i++;
	}
	return false;
}

bool	check_alpha(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isalpha(str[i]) && !std::isspace(str[i])) 
			return false;
		i++;
	}
	return true;
}

std::string	trim(std::string str)
{
	
	int	i;
	int	j;

	while (std::isspace(str[0]))
	{
		for (i = 0; str[i]; i++)
			str[i] = str[i + 1];
	}
	i = 0;
	while (str[i])
	{
		while (std::isspace(str[i]) && std::isspace(str[i + 1]))
		{
			for (j = i; str[j]; j++)
				str[j] = str[j + 1]; 
		}
		i++;
	}
	while (std::isspace(str[--i]))
		str[i] = '\0';
	return str;
}

int main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
		//else if (input == "SEARCH")
		//	phonebook.searchContacts();
		else if (input == "EXIT")
		{
			std::cout << "Exiting PhoneBook. Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}