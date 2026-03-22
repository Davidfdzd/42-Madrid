#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;

    return true;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, value;

        if (!std::getline(ss, date, ',') || !std::getline(ss, value))
            continue;

        _db[date] = std::atof(value.c_str());
    }
}

double BitcoinExchange::getRateForDate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

    if (it != _db.end() && it->first == date)
        return it->second; //si existe fecha

    if (it == _db.begin()) //no hay fecha anterior
        throw std::runtime_error("Error: bad input => " + date);

    --it; //si no existe fecha usamos anterior
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, sep, valueStr;

        if (!(ss >> date >> sep >> valueStr) || sep != "|")
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value = std::atof(valueStr.c_str());
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        try
        {
            double rate = getRateForDate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}