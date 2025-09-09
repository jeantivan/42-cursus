#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(): _firstName(""), _lastName(""), _nickName(""), _secret(""), _phoneNumber("")
{
}

void Contact::updateContact(std::string firstName, std::string lastName, std::string nickName, std::string secret, std::string phoneNumber)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_secret = secret;
	_phoneNumber = phoneNumber;
}

std::string Contact::getFirstName(void)
{
	return (_firstName);
}

std::string Contact::getLastName(void)
{
	return (_lastName);
}

std::string Contact::getNickName(void)
{
	return (_nickName);
}

std::string Contact::getSecret(void)
{
	return (_secret);
}

std::string Contact::getPhoneNumber(void)
{
	return (_phoneNumber);
}

void Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
	_nickName = nickName;
}

void Contact::setSecret(std::string secret)
{
	_secret = secret;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}
