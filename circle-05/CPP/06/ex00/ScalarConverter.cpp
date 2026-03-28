#include "ScalarConverter.hpp"

// This isn't used the class is Abstract
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isInt(const std::string &input)
{
	char *end;
	long val;

	if (input.empty())
		return false;
	errno = 0;
	val = std::strtol(input.c_str(), &end, 10);
	return (end == input.c_str() + input.length() && errno == 0 && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string &input)
{
	char *end;
	if (input.empty())
		return false;
	errno = 0;
	std::strtof(input.c_str(), &end);
	if (input.c_str() == end || *end != 'f' || *(end + 1) || errno != 0)
		return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string &input)
{
	char *end;

	if (input.empty())
		return false;
	errno = 0;
	std::strtod(input.c_str(), &end);
	if (input.c_str() == end || *end || errno != 0)
		return false;
	return true;
}

// Detect de literal type of input
ELiteral ScalarConverter::detectLiteral(const std::string &input)
{
	std::string pseudos[] = {"nan", "+nan", "-nan", "nanf", "+nanf", "-nanf", "inf", "+inf", "-inf", "inff", "+inff", "-inff"};
	for (int i = 0; i < 12; i++)
	{
		if (input == pseudos[i])
			return (PSEUDO);
	}
	if (input.length() == 1 && !std::isdigit(input[0]))
		return (CHAR);
	if (isInt(input))
		return (INT);
	if (isFloat(input))
		return (FLOAT);
	if (isDouble(input))
		return (DOUBLE);
	return (INVALID);
}

void ScalarConverter::printPseudo(const std::string &pseudo)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (pseudo.find("nan") != std::string::npos)
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else
	{
		std::cout << "float: " << (pseudo[pseudo.length() - 2] == 'f' ? pseudo : pseudo + 'f') << "\n";
		std::cout << "double: " << (pseudo[pseudo.length() - 2] == 'f' ? pseudo.substr(0, pseudo.length() - 1) : pseudo) << "\n";
	}
}

void ScalarConverter::convert(const std::string &input)
{
	ELiteral scalarType = detectLiteral(input);
	char c;
	int i;
	float f;
	double d;

	switch (scalarType)
	{
	case PSEUDO:
		printPseudo(input);
		return;
	case CHAR:
		c = input[0];
		std::cout << "char: ";
		if (!std::isprint(c))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << c << "'" << "\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << std::setprecision(1) << std::fixed << "float: " << static_cast<float>(c) << "f\n";
		std::cout << std::setprecision(1) << std::fixed << "double: " << static_cast<double>(c) << "\n";
		break;
	case INT:
		i = std::atoi(input.c_str());
		std::cout << "char: ";
		if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
			std::cout << "impossible\n";
		else if (!std::isprint(static_cast<char>(i)))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << static_cast<char>(i) << "'" << "\n";
		std::cout << "int: " << i << "\n";
		std::cout << std::setprecision(1) << std::fixed << "float: " << static_cast<float>(i) << "f\n";
		std::cout << std::setprecision(1) << std::fixed << "double: " << static_cast<double>(i) << "\n";
		break;
	case FLOAT:
		f = std::strtof(input.c_str(), NULL);
		std::cout << "char: ";
		if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
			std::cout << "impossible\n";
		else if (!std::isprint(static_cast<char>(f)))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << static_cast<char>(f) << "'" << "\n";
		std::cout << "int: ";
		if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(f) << "\n";
		std::cout << std::setprecision(1) << std::fixed << "float: " << f << "f\n";
		std::cout << std::setprecision(1) << std::fixed << "double: " << static_cast<double>(f) << "\n";
		break;
	case DOUBLE:
		d = std::strtod(input.c_str(), NULL);
		std::cout << "char: ";
		if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
			std::cout << "impossible\n";
		else if (!std::isprint(static_cast<char>(d)))
			std::cout << "Non displayable\n";
		else
			std::cout << "'" << static_cast<char>(d) << "'" << "\n";
		std::cout << "int: ";
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(d) << "\n";

		std::cout << std::setprecision(1) << std::fixed << "float: ";

		// Check if the double value can be represented as a float without overflow
		// std::numeric_limits<float>::min() is the smallest positive normal float, that's why we use max() to check for overflow in both directions
		if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
			std::cout << "impossible\n";
		else
			std::cout << static_cast<float>(d) << "\n";
		std::cout << std::setprecision(1) << std::fixed << "double: " << static_cast<double>(d) << "\n";
		break;
	default:
		std::cout << "Invalid conversion to any scalar type (char, int, float, double)\n";
		return;
	}
}
