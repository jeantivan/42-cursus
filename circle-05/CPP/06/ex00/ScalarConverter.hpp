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

	template<typename T>
	static bool checkLimits(ELiteral scalarLiteral, int i, float f, double d) {
		return (
		(scalarLiteral == INT && (i < static_cast<int>(std::numeric_limits<T>::min()) || i > static_cast<int>(std::numeric_limits<T>::max())))
		|| (scalarLiteral == FLOAT && (f < static_cast<float>(std::numeric_limits<T>::min()) || f > static_cast<float>(std::numeric_limits<T>::max())))
		|| (scalarLiteral == DOUBLE && (d < static_cast<double>(std::numeric_limits<T>::min()) || d > static_cast<double>(std::numeric_limits<T>::max()))));
	}

public:
	static void convert(const std::string& str);
};

#endif // SCALARCONVERTER_HPP
