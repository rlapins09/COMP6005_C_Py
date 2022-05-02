// Homework 5: Contacts Elana Lapins
// Programming for Engineers, due: 10/29/2021

#include <iostream>
#include <string>
#include <map>
//#include "contact.h"

// just the class declration. No actual running code
class Contact {
public:
	std::string firstName, lastName, phoneNumber, address;
	Contact();
	Contact(std::string const& firstName, std::string const& lastName,
		std::string const& phoneNumber, std::string const& address);
};

// Implementation of the member fucntions
Contact::Contact() {
}
Contact::Contact(std::string const& firstName, std::string const& lastName,
	std::string const& phoneNumber, std::string const& address)
{
	//INITIALIZE CONTACT USING CONSTRUCTOR ARGUMENTS
	Contact c;

	c.firstName = firstName;
	c.lastName = lastName;
	c.phoneNumber = phoneNumber;
	c.address = address;
}

//other functions:
std::ostream& operator<<(std::ostream& os, const Contact& c) {
	//PRINT information about contact c
	os << "Name: " << c.firstName << " "<< c.lastName<< "\n";
	os << "Phone Number: " << c.phoneNumber << "\n";
	os << "E-mail: " << c.address << "\n" << std::endl;
	
	

	return os;
}

using ContactManager = std::map<std::string, Contact>;


void read_name(std::string& first, std::string& last) {
//read first and last name and return those strings through the reference arguments
	std::string firstName, lastName;
	firstName = first;
	lastName = last;

}

void list_contacts(const ContactManager& contacts) {
	//check if contacts is empty and handle it
	if (contacts.empty() == true) {
		std::cout <<"no contacts\n";
	}
	else {
		for (auto& key_value_pair : contacts) {

			//PRINT ONLY NAMES
			std::cout <<  key_value_pair.first << "\n";
		}
	}
}


void add_contact(ContactManager& contacts) {
	
	Contact new_contact;

	std::cout << "first name: ";
	std::cin >> new_contact.firstName;
	std::cout << "last name: ";
	std::cin >> new_contact.lastName;
	std::cout << "phone number: ";
	std::cin >> new_contact.phoneNumber;
	std::cout << "e-mail: ";
	std::cin >> new_contact.address;

	std::string add;
	add = new_contact.lastName + ", " + new_contact.firstName;

	//ADD: if contact exists you have to overwrite it with the new contact
	if (contacts.count(add) > 0) {
		std::map<std::string, Contact>::iterator iter;
		iter = contacts.find(add);
		if (iter != contacts.end()) {
			iter->second = new_contact;
		}	
	}
	else {
		contacts.insert(std::pair<std::string,Contact>(add, new_contact));
	}
	 
}

//Remove contact
void remove_contact(ContactManager& contacts) {
	std::string remove, f, l;
	std::cout << "first name: ";
	std::cin >> f;
	std::cout << "last name: ";
	std::cin >> l;
	remove = l + ", " + f;

	if (contacts.count(remove) > 0) {
	contacts.erase(remove);
	std::cout << "removed " << f << " " << l << "\n";
	}
	else {
		std::cout << "contact not found\n";
	}
}

void find_contact(const ContactManager& contacts) {
	std::string first_name, last_name;
	//ADD: read first and last name
	std::cout << "first name: ";
	std::cin >> first_name;
	std::cout << "last name: ";
	std::cin >> last_name;

	//values in map are ordered by key, so alst name must go first
	std::string const key = last_name + ", " + first_name;
	auto it = contacts.find(key);

	if (it == std::end(contacts)) {
		//ADD: handle case contact is not in variable "contacts"
		std::cout << "contact not found\n";
	}
	else {
		//it->first is the key, it->second is the value in the std::map
		Contact const& c = it->second;

		//ADD: print contact information
		std::cout << (c);
	}
}

int main() {
	std::string cmd;
	ContactManager contacts;

	std::cout <<"> ";
	std::cin >> cmd;

	do {
		if (cmd == "exit") {
			break;
		}
		else if (cmd == "list") {
			list_contacts(contacts);
		}
		else if (cmd == "add") {
			add_contact(contacts);
		}
		else if (cmd == "remove") {
			remove_contact(contacts);
		}
		else if (cmd == "find") {
			find_contact(contacts);
		}
		std::cout << "> ";
	} while (std::cin >> cmd);
	return 0;
}
