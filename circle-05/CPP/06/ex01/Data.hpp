#ifndef DATA_HPP
# define DATA_HPP

#include <string>

class Data
{
private:
	std::string name;

public:
	Data();
	Data(const std::string& n);
	Data(const Data &other);
	~Data();
	Data &operator=(const Data &other);

	const std::string& getName() const;
	void setName(const std::string& newName);
};

#endif // DATA_HPP
