#include "phonebook.hpp"

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
		input = phonebook.trim(input);
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
