
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cctype>

class	Contact
{
	public:
		Contact(void);
		~Contact(void);
		void		setIndex(int index);
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickName(std::string nickName);
		void		setPhoneNumber(std::string phoneNumber);
		void		setDarkestSecret(std::string darkestSecret);
		int			getIndex(void) const;
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
	//	void	searchContacts(void) const;
	private:
		Contact	_contacts[8];
		void	_displace_contacts(void);
};

std::string	trim(std::string str);
//std::string	format(std::string str);
bool		check_spaces(std::string str);
bool		check_alpha(std::string str);

#endif
