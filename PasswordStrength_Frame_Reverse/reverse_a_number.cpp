// Elana Lapins - Homework 4: Reverse a Number
// Programming for Engineers, due: 10/01/2021

#include<iostream>
#include<cmath>
#include<string>


bool isWholeNumber(std::string input_string) {
	bool b;
	for (int ii = 0; ii < input_string.length(); ii++) {
		b = std::isdigit(input_string[ii]);
		if (b == false) {
			break;
		}
	}
	return b;
}


int reverse_number(int number) {int remainder = 0;
	int reversed = 0;
	/*int length = trunc(log10(number)) + 1;*/
	int array[] = { number };
	int length = sizeof(array) / sizeof(array[0]);
	for (int j = 0; j < length ; j++) {
		while (array[j] != 0) {
			remainder = array[j] % 10;
			reversed = reversed * 10 + remainder;
			array[j] /= 10;
		}
	return reversed;
	}
}

int main() {
	int cases;
	int R;
	std::string input_string;
	int num;
	bool tf;
	std::cin >> cases;

	for (int i = 0; i < cases; i++) {
		std::cout << "Case " << i << ":\n";
		std::cin >> input_string;

		// add function to check if valid
		tf = isWholeNumber(input_string);

		if (tf == true) {
		num = std::stoi(input_string, nullptr);
		R = reverse_number(num);
		std::cout << R << "\n";
		}
		else {
			std::cout << "Invalid input" << "\n";
		}

		
	}
}