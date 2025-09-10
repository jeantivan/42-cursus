#ifndef FILEREPLACE_HPP
# define FILEREPLACE_HPP

#include <string>
#include <fstream>

class FileReplace
{
private:
	std::string _filename;
	std::string _new_filename;
	std::string _str_to_replace;
	std::string _new_str;
	std::ifstream _file;
	std::ofstream _new_file;

public:
	FileReplace(std::string filename, std::string str_to_replace, std::string new_str);
	~FileReplace();

	void readFile();
};

#endif // FILEREPLACE_HPP
