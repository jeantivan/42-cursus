#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook():  _curr_index(0), _size(0)
{
	std::cout << "Welcome to My amazing PhoneBook" << std::endl;
}

void PhoneBook::showInstructions()
{
	std::cout << "Type a command:" << std::endl;
	std::cout << "  \"ADD\" to save a contact." << std::endl;
	std::cout << "  \"SEARCH\" to search a contact." << std::endl;
	std::cout << "  \"EXIT\" to std::exit the phone book." << std::endl;
}

void PhoneBook::bye(bool isEOF)
{
	std::cout << "\nBye Bye!";
	if (isEOF)
		std::cout << " (EOF reached)";
	std::cout << std::endl;
}

void PhoneBook::init()
{
	std::string cmd;

	showInstructions();
	while (1)
	{
		std::cout << ">> ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			(bye(true),std::exit(1));
		if (cmd == "EXIT")
		{
			bye();
			break ;
		}
		else if (cmd == "ADD")
			addContact();
		else if (cmd == "SEARCH")
			searchContact();
		else
			wrongInput();
	}
}

void PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string secret;
	std::string phoneNumber;

	std::cout << "Adding a new contact." << std::endl;
	do
	{
		std::cout << "First name: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			(bye(true),std::exit(1));
	} while (firstName.empty());

	do
	{
		std::cout << "Last name: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			(bye(true),std::exit(1));
	} while (lastName.empty());

	do
	{
		std::cout << "Nick name: ";
		std::getline(std::cin, nickName);
		if (std::cin.eof())
			(bye(true),std::exit(1));
	} while (nickName.empty());

	do
	{
		std::cout << "Secret name: ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
			(bye(true),std::exit(1));
	} while (secret.empty());

	do
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			(bye(true),std::exit(1));
	} while (phoneNumber.empty());

	contacts[_curr_index].updateContact(firstName, lastName, nickName, secret, phoneNumber);

	if (_size < 8)
		_size++;
	_curr_index++;
	if (_curr_index >= 8)
		_curr_index = 0;

}

bool PhoneBook::validIndex(std::string searchIndex)
{
	if (searchIndex.empty())
		return (false);
	if (!std::isdigit((int)searchIndex.at(0)))
	{
		std::cout << "Use only digits (1 - 8)" << std::endl;
		return (false);
	}
	if (searchIndex.length() > 1)
	{
		std::cout << "Too long!" << std::endl;
		return (false);
	}
	if (searchIndex.at(0) - '0' < 1 || searchIndex.at(0) - '0' > static_cast<int>(_size))
	{
		std::cout << "Index out of bounds!" << std::endl;
		return (false);
	}
	return (true);
}

void PhoneBook::searchContact()
{
	std::string searchIndex;

	if (_size < 1)
		std::cout << "  Contact list is empty!  " << std::endl;
	else
	{
		showContactTable();
		do {
			std::cout << ">> Insert contact index: ";
			std::getline(std::cin, searchIndex);
			if (std::cin.eof())
				(bye(true),std::exit(1));
			if (searchIndex == "EXIT")
				break;
		} while (!validIndex(searchIndex));
		if (searchIndex != "EXIT")
			showContactInfo(searchIndex.at(0) - '0' - 1);
	}
}

std::string PhoneBook::truncateData(std::string src)
{
	if (src.length() > 10)
		return (src.substr(0, 9) + ".");
	return (src);
}

void PhoneBook::showContactTable()
{
	std::cout << std::endl;
	std::cout << "  ·" << std::setfill('~') << std::setw(45) << "·" << std::endl;
	std::cout << "  |" << std::setfill(' ') << std::setw(10) << "Index" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "First name"  << "|" ;
	std::cout << std::setfill(' ') << std::setw(10) << "Last name"  << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "Nick name" << "|" << std::endl;
	std::cout << "  ·" << std::setfill('~') << std::setw(45) << "·" << std::endl;
	for(size_t i = 0; i < _size; i++)
	{
		std::cout << "  |" << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		std::cout << std::setfill(' ') << std::setw(10) << truncateData(contacts[i].getFirstName()) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << truncateData(contacts[i].getLastName()) << "|";
		std::cout << std::setfill(' ') << std::setw(10) << truncateData(contacts[i].getNickName()) << "|" << std::endl;
		std::cout << "  ·" << std::setfill('~') << std::setw(45) << "·" << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::showContactInfo(int index)
{
	Contact contact = contacts[index];
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nick name: " << contact.getNickName() << std::endl;
	std::cout << "Secret: " << contact.getSecret() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
}

void PhoneBook::wrongInput()
{
	std::cout << "Wrong input, please try again!" << std::endl;
}
