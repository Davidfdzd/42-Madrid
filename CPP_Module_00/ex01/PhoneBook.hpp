#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

std::string formatField(const std::string& str);

class PhoneBook{
private:
    Contact contacts[8];
    int number_contacts;

public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact() const;
};

#endif