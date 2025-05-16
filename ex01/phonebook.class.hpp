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
		void	addContact(void);
		void	searchContacts(void) const;
	private:
		Contact		_contacts[8];
		std::string	_fillInfo(std::string const str, int type);
		std::string	_truncateInfo(std::string str) const;
		void		_promptAndDisplay(void) const;
		void		_displace_contacts(void);
};

#endif