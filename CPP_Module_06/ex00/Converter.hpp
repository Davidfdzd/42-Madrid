#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

enum LiteralType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

bool isChar(const std::string &literal);
bool isInt(const std::string &literal);
bool isFloat(const std::string &literal);
bool isDouble(const std::string &literal);
bool isPseudoLiteral(const std::string &literal);

LiteralType detectType(const std::string &literal);

#endif