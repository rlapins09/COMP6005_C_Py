// HW1 Problem 1: Celsius-Farenheit
// Elana Lapins 9/4/2021

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int Farenheit; //Farenheit input - always an int
	int Celsius1; // Celsius output value as int
	double Celsius2;// Celsius output value as double;

	for (int a = 0; a < 1; a++) {
		int cases;
		std::cin >> cases;

		for (int i = 0; i < cases; i++) {
			std::cin >> Farenheit;
			Celsius1 = (Farenheit - 32) / 1.8;
			Celsius2 = (Farenheit - 32) / 1.8;

			std::cout << "Case " << i << ":\n";
			std::cout << Farenheit << "F = " << Celsius1 << "C\n";
			std::cout << Farenheit << "F = " << Celsius2 << "C\n";
		}
	}

}