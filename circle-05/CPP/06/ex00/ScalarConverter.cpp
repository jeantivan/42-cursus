#include "ScalarConverter.hpp"

// This isn't used the class is Abstract
ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


bool ScalarConverter::isInt(const std::string& input) {
	char *end;
	long val;

	if (input.empty())
		return false;
	errno = 0;
	val = std::strtol(input.c_str(), &end, 10);
	return (end == input.c_str() + input.length() && errno == 0 && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat(const std::string& input) {
	char *end;

	if (input.empty())
		return false;
	errno = 0;
	std::strtof(input.c_str(), &end);
	std::string end_str = end;

	return (end_str[0] == 'f' && end_str.length() == 1 && errno == 0);
}

bool ScalarConverter::isDouble(const std::string& input) {
	char *end;

	if (input.empty())
		return false;
	errno = 0;
	std::strtod(input.c_str(), &end);
	return (end == input.c_str() + input.length() && errno == 0);
}


// Detect de literal type of input
ELiteral ScalarConverter::detectLiteral(const std::string& input) {
	std::string pseudos[] = {"nan", "+nan", "-nan", "nanf", "+nanf", "-nanf", "inf", "+inf", "-inf", "inff", "+inff", "-inff"};
	for (int i = 0; i < 12; i++) {
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

void ScalarConverter::printPseudo(const std::string& pseudo) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (pseudo.find("nan") != std::string::npos)
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	} else {
		std::cout << "float: " << (pseudo[pseudo.length() - 2] == 'f' ? pseudo : pseudo + 'f') << "\n";
		std::cout << "double: " << (pseudo[pseudo.length() - 2] == 'f' ? pseudo.substr(0, pseudo.length() - 1) : pseudo) << "\n";
	}
}

void ScalarConverter::convert(const std::string& input) {
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
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		break;
	case INT:
		i = std::atoi(input.c_str());
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		break;
	case FLOAT:
		f = std::strtof(input.c_str(), NULL);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		break;
	case DOUBLE:
		d = std::strtod(input.c_str(), NULL);
		c = static_cast<double>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		break;
	default:
		std::cout << "Invalid conversion to any scalar type (char, int, float, double)\n";
		return;
	}


	std::cout << "char: ";
	if (checkLimits<char>(scalarType, i, f, d))
		std::cout << "impossible\n";
	else
	{
		if (!std::isprint(c))
			std::cout << "Non displayable\n";
		else
			std::cout << c << "\n";
	}

	std::cout << "int: ";
	if (checkLimits<int>(scalarType, i, f, d))
		std::cout << "impossible\n";
	else
		std::cout  << i << "\n";
	std::cout << std::setprecision(1) << std::fixed;

	std::cout << "float: ";
	if (checkLimits<float>(scalarType, i, f, d))
		std::cout << "impossible\n";
	else
		std::cout  << i << "\n";

	std::cout << "double: " << d << "\n";
}
