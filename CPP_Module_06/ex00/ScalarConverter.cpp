#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string &literal)
{
	LiteralType type = detectType(literal);
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	try
	{
		switch (type)
		{
            case CHAR:
                c = literal[0];
                i = static_cast<int>(c);
                f = static_cast<float>(c);
                d = static_cast<double>(c);
                break;
            case INT:
                i = std::atoi(literal.c_str());
                c = static_cast<char>(i);
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                break;
            case FLOAT:
                f = static_cast<float>(std::atof(literal.c_str()));
                c = static_cast<char>(f);
                i = static_cast<int>(f);
                d = static_cast<double>(f);
                break;
            case DOUBLE:
                d = std::atof(literal.c_str());
                c = static_cast<char>(d);
                i = static_cast<int>(d);
                f = static_cast<float>(d);
                break;
            case PSEUDO:
                if (literal == "nan" || literal == "nanf")
                {
                    f = std::numeric_limits<float>::quiet_NaN();
                    d = static_cast<double>(f);
                }
                else if (literal == "+inf" || literal == "+inff")
                {
                    f = std::numeric_limits<float>::infinity();
                    d = static_cast<double>(f);
                }
                else if (literal == "-inf" || literal == "-inff")
                {
                    f = -std::numeric_limits<float>::infinity();
                    d = static_cast<double>(f);
                }
                else
                {
                    f = 0.0f;
                    d = 0.0;
                }
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << f << "f" << std::endl;
                std::cout << "double: " << d << std::endl;
                return;
            
            default:
                std::cout << "Conversion impossible: unknown literal type" << std::endl;
                return;
		}
		if (std::isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char : Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Conversion failed: " << e.what() << std::endl;
	}
}