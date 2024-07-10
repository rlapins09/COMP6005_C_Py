// Elana Lapins - Homework 3 Problem 2: Find Max and Min
// Programming for Engineers, due: 09/24/2021

#include <iostream>
#include <string>

void FIND_MIN_MAX(int size, int ARRAY[], int RESULTS[]) {
	int min = ARRAY[0];
	int max = ARRAY[0];

	for (int m = 0; m < size; m++) {
		if (min > ARRAY[m]) {
			min = ARRAY[m];
		}
		else if (max < ARRAY[m]) {
			max = ARRAY[m];
		}
		RESULTS[0] = min;
		RESULTS[1] = max;
	}
}

void main() {
	int cases = 0;
	std::cin >> cases;
	int array[256];
	int num = 0;
	int results[2];
	int MIN = 0;
	int MAX = 0;

	for (int i = 0; i < cases; i++) {
		std::cout << "Case " << i << ":\n";
		std::cin >> num;

		for (int j = 0; j < num; j++) {
			std::cin >> array[j];
			//std::cout << array[j] << "\n";
			FIND_MIN_MAX(num, array, results);
			MIN = results[0];
			MAX = results[1];
		}
		std::cout << "Min: " << MIN << "\n";
		std::cout << "Max: " << MAX << "\n";
	}
}