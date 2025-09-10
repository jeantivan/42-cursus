#include "FileReplace.hpp"
#include <iostream>

FileReplace::FileReplace(
	std::string filename,
	std::string str_to_replace,
	std::string new_str)
{
	_filename = filename;
	_new_filename = filename + ".replace";
	_str_to_replace = str_to_replace;
	_new_str = new_str;
	_file.open(filename.data(), std::ifstream::in);
}


FileReplace::~FileReplace() {
	if (_file)
		_file.close();
	if (_new_file)
		_new_file.close();
}

void FileReplace::readFile() {
	std::string line;
	size_t pos;

	if (_file.fail())
	{
		std::cerr << "Error: could not open file " << _filename << std::endl;
		return ;
	}
	_new_file.open(_new_filename.data(), std::ios::out);
	if (_new_file.fail())
	{
		std::cerr << "Error: could not open file " << _new_filename << std::endl;
		return ;
	}
	while (!_file.eof())
	{
		std::getline(_file, line);
		pos = line.find(_str_to_replace);
		while (pos != std::string::npos)
		{
			line = line.substr(0, pos) + _new_str + line.substr(pos + _str_to_replace.length());
			pos = line.find(_str_to_replace);
		}
		_new_file << line << std::endl;
	}
}
