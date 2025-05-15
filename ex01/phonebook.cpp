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

bool	check_digits(std::string str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool	check_phone(std::string str)
{
	int	i;

	if ((str[0] != '+' || (str[0] == '+' && !str[1])) && !std::isdigit(str[0]))
		return false;
	i = 1;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && !std::isspace(str[i])) 
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
	
	std::cout << Y
		<< "                                                                                                        __" << std::endl
		<< " _ _ _     _ _                      _          _   _          _____ _               _____         _    |  |" << std::endl
		<< "| | | |___| | |___ ___ _____ ___   | |_ ___   | |_| |_ ___   |  _  | |_ ___ ___ ___| __  |___ ___| |_  |  |" << std::endl
		<< "| | | | -_| | |  _| . |     | -_|  |  _| . |  |  _|   | -_|  |   __|   | . |   | -_| __ -| . | . | '_| |__|" << std::endl
		<< "|_____|___|_|_|___|___|_|_|_|___|  |_| |___|  |_| |_|_|___|  |__|  |_|_|___|_|_|___|_____|___|___|_,_| |__|" << RS
		<< std::endl;
	while (true)
	{
		std::cout << std::endl << C << "Please enter a command (ADD, SEARCH, EXIT): " << RS;
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContacts();
		else if (input == "EXIT")
		{
			std::cout << Y
				<< "                                     __	" << std::endl
				<< " _____           _    _             |  |" << std::endl
				<< "|   __|___ ___ _| |  | |_ _ _ ___   |  |" << std::endl
				<< "|  |  | . | . | . |  | . | | | -_|  |__|" << std::endl
				<< "|_____|___|___|___|  |___|_  |___|  |__|" << std::endl
				<< "                         |___|          " << RS << std::endl
				<< std::endl;
			break;
		}
		else
			std::cout << R << "Invalid command. Please try again." << RS << std::endl;
	}
	return 0;
}
