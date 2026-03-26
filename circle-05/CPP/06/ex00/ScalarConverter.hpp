#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cerrno>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

// Literal types
enum ELiteral {
	INVALID = -1,
	PSEUDO,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter
{
private:
	// Make the class not instantiable
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);


	static bool isInt(const std::string& str);
	static bool isFloat(const std::string& str);
	static bool isDouble(const std::string& str);

	static ELiteral detectLiteral(const std::string& input);
	static void printPseudo(const std::string& pseudo);
public:
	static void convert(const std::string& str);
};

#endif // SCALARCONVERTER_HPP
