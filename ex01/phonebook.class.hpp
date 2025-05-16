#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "contact.class.hpp"

class	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		addContact(void);
		void		searchContacts(void);
		std::string	trim(std::string str);
	private:
		Contact		_contacts[8];
		bool		_check_phone(std::string str) const;
		bool		_check_digits(std::string str) const;
		bool		_check_alpha(std::string str) const;
		bool		_check_spaces(std::string str) const;
		std::string	_fillInfo(std::string const str, int type);
		std::string	_truncateInfo(std::string str) const;
		void		_promptAndDisplay(void);
		void		_displace_contacts(void);
};

#endif