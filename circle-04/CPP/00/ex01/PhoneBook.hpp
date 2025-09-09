#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
	private:
		size_t _curr_index;
		size_t _size;
		Contact contacts[8];

	public:
		PhoneBook();
		void init();
		void showInstructions();
		void bye();
		void addContact();
		void searchContact();
		void wrongInput();
		void showContactTable();
		void showContactInfo(int index);
		bool validIndex(std::string index);
		std::string truncateData(std::string src);
};

#endif // PHONEBOOK_HPP
