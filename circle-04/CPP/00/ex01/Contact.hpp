#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _secret;
		std::string	_phoneNumber;

	public:
		// Constructor
		Contact();

		// Getters
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getSecret();
		std::string getPhoneNumber();

		// Setters
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setNickName(std::string nickName);
		void setSecret(std::string secret);
		void setPhoneNumber(std::string phoneNumber);

		void updateContact(std::string firstName, std::string lastName, std::string nickName, std::string secret, std::string phoneNumber);
};

#endif // CONTACT_HPP
