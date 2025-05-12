
#include "phonebook.hpp"

Contact::Contact(void) : _index(0), _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret(""){}

Contact::~Contact(void){}

int	Contact::_counter = 0;

//setters
void		Contact::setIndex(int index){this->_index = index;}
void		Contact::setFirstName(std::string firstName){ this->_firstName = firstName; }
void		Contact::setLastName(std::string lastName){ this->_lastName = lastName; }
void		Contact::setNickName(std::string nickName){ this->_nickName = nickName; }
void		Contact::setPhoneNumber(std::string phoneNumber){ this->_phoneNumber = phoneNumber; }
void		Contact::setDarkestSecret(std::string darkestSecret){ this->_darkestSecret = darkestSecret; }

//getters
int			Contact::getIndex(void) const { return(this->_index); }
std::string	Contact::getFirstName(void) const { return(this->_firstName); }
std::string	Contact::getLastName(void) const { return(this->_lastName); }
std::string	Contact::getNickName(void) const { return(this->_nickName); }
std::string	Contact::getPhoneNumber(void) const { return(this->_phoneNumber); }
std::string	Contact::getDarkestSecret(void) const { return(this->_darkestSecret); }
