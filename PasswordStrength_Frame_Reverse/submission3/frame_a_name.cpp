// Elana Lapins - Homework4: Frame a Name
// Programming for Engineers, due: 10/01/2021

#include<iostream>
#include<string>
#include<iomanip>


void print_frame(int length) {
	for (int ii = 0; ii < length; ii++) {
		std::cout << "*";
	}
	std::cout << "\n";
}


int main() {
	int cases;
	std::cin >> cases;

	for (int i = 0; i < cases; i++) {
		std::string name;
		std::cout << "Case " << i << ":\n";
		if (i == 0) {
			std::cin.ignore();
		}
		std::getline(std::cin, name);
		size_t name_length = name.length();
		size_t length;
		size_t space_welcome;

		std::string welcome = "* Welcome to my program ";
		std::string hello = "* Hello, ";
		
		if ((name_length + hello.length()) < welcome.length()) {
			length = welcome.length() +1 ;
			space_welcome = length - welcome.length();
			
		}
		else {
			length = name_length + hello.length() + 2;
			space_welcome = length - welcome.length()+ 1;
		}

		int int_length = static_cast<int>(length);

		print_frame(int_length);
		std::cout << "*" << std::setw(length) << "*\n";
		std::cout << hello << name << std::setw(length - name.length() - hello.length() + 1)<< "*\n";
		std::cout << welcome << std::setw(space_welcome)<< "*\n";
		std::cout << "*" << std::setw(length) << "*\n";
		print_frame(int_length);
	}

}