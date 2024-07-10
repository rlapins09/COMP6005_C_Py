// Elana Lapins - Homework 2 Problem 3: Leibniz
// Programming for Engineers, due: 09/17/2021

#include <iostream>
#include<cmath>
#include<iomanip>

int main() {
	int cases = 0;
	std::cin >> cases;
	//double Pi = 0;
	//double pifour = 0;

	// Leibniz series: pi/4 = sum(n=0 -> inf) { 1 - (-1)^n / (2n+3) }

	for (int i = 0; i < cases; i++) {
		double n = 0;
		std::cout << "Case " << i << ":\n";
		std::cin >> n;
		double Pi = 0;
		double pifour = 0;

		for (double N = 0; N <= n - 1; N++) {
			pifour += (pow(-1, N)) / (2 * N + 1);
		}
		Pi = pifour * 4;
		std::cout << "Pi estimated as: " << std::fixed << std::setprecision(8) << Pi << "\n";
	}
}