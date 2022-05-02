// Elana Lapins - Homework 3 Problem 1: Preventing floating point overflow
// Programming for Engineers, due: 09/24/2021
#include <iostream>
#include <string>


void main() {
	double in = 0;
	int cases = 0;
	std::cin >> cases;

	for (int i = 0; i < cases; i++) {
		std::cin >> in;
		std::cout << "Case " << i << ":\n";

		float F = static_cast<float>(in);

		if (F >= std::numeric_limits<float>::max() || F <= std::numeric_limits<float>::lowest()) {
			std::cout << in << " will overflow a float\n";
		}
		else {
			std::cout << in << " won't overflow a float, float = " << F << "\n";
		}

	}

}