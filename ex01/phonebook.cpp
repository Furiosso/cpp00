#include "phonebook.hpp"

bool	check_spaces(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isspace(str[i]))
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
		if ((i == 0 && isspace(str[i]))
			|| (!isalpha(str[i]) && !isspace(str[i]))
			|| (isspace(str[i]) && str[i + 1] && isspace(str[i + 1]))
			|| (i == (str.length() - 1) && isspace(str[i]))) 
			return false;
		i++;
	}
	return true;
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