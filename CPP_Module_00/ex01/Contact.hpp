#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

#define RED    "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"
#define GREY    "\033[90m"
#define BLUE "\033[34m"

class Contact{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();
    ~Contact();

    void setFirst_name(std::string str);
    void setLast_name(const std::string str);
    void setNickname(const std::string str);
    void setPhone_number(const std::string str);
    void setDarkest_secret(const std::string str);

    std::string getFirst_name() const;
    std::string getLast_name() const;
    std::string getNickname() const;
    std::string getPhone_number() const;
    std::string getDarkest_secret() const;
    void displayContact() const;
};

#endif