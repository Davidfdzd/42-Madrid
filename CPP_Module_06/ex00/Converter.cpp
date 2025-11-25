#include "Converter.hpp"

LiteralType detectType(const std::string &literal)
{
   	size_t i = 0;
	//	PSEUDO //
   {
		if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff")
        return (PSEUDO);
	}
	//	CHAR //
    {
		if (literal.length() == 1 && !std::isdigit(literal[0]))
        	return (CHAR);
	}
	//	INT //
    {
		bool isInt = true;
    	if (literal[i] == '+' || literal[i] == '-')
    	    i++;
    	for (; i < literal.length(); ++i)
    	{
    	    if (!std::isdigit(literal[i]))
    	    {
    	        isInt = false;
    	        break;
    	    }
    	}
    	if (isInt)
    	    return (INT);
	}
	//	FLOAT //
	{
		if (literal[literal.length() - 1] == 'f')
		{
			bool hasDot = false;
			bool valid = true;
			i = 0;
			if (literal[i] == '+' || literal[i] == '-')
				i++;
			for (; i < literal.length() - 1; ++i)
			{
				if (literal[i] == '.')
				{
					if (hasDot)
					{
						valid = false;
						break;
					}
					hasDot = true;
				}
				else if (!std::isdigit(literal[i]))
				{
					valid = false;
					break;
				}
			}
			if (valid && hasDot)
				return (FLOAT);
		}
    }
	//	DOUBLE //
	{
    	bool hasDot = false;
    	bool valid = true;
    	i = 0;
    	if (literal[i] == '+' || literal[i] == '-')
    		i++;
    	for (; i < literal.length(); ++i)
    	{
    	    if (literal[i] == '.')
    	    {
    	        if (hasDot) { valid = false; break; }
    	        hasDot = true;
    	    }
    	    else if (!std::isdigit(literal[i]))
    	    {
    	        valid = false;
    	        break;
    	    }
    	}
    	if (valid && hasDot)
    	    return (DOUBLE);
	}
	// PSEUDO //
	return (PSEUDO);
}