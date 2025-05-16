
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <iomanip>
# include "contact.class.hpp"
# include "phonebook.class.hpp"

# define RS	"\033[0m"
# define R	"\033[31m"
# define G	"\033[32m"
# define Y	"\033[33m"
# define M	"\033[35m"
# define C	"\033[36m"

std::string	trim(std::string str);
int			get_length(std::string str);
bool		check_digits(std::string str);
bool		check_phone(std::string str);
bool		check_spaces(std::string str);
bool		check_alpha(std::string str);

#endif
