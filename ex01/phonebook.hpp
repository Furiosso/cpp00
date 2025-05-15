
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <cstring>
# include <iomanip>

# define RS	"\033[0m"
# define R	"\033[31m"
# define G	"\033[32m"
# define Y	"\033[33m"
# define M	"\033[35m"
# define C	"\033[36m"

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickName(std::string nickName);
		void		setPhoneNumber(std::string phoneNumber);
		void		setDarkestSecret(std::string darkestSecret);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
	private:
		static int	_counter;
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

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

std::string	trim(std::string str);
bool		check_digits(std::string str);
bool		check_phone(std::string str);
bool		check_spaces(std::string str);
bool		check_alpha(std::string str);

#endif
