// Elana Lapins - Homework 2 Problem 2: Worth Every Penny
// Programming for Engineers, due: 09/17/2021

#include<iostream>
#include<iomanip>
#include<cstdint>

//the first ring is sold for 25 cents ($0.25), the second one for $10.25, the third one $20.25 and so on

void main() {
	int cases = 0;
	std::cin >> cases;
	int n = 0;

	for (int i = 0; i < cases; i++) {
		std::cin >> n;
		std::cout << "Case " << i << ":\n";
		std::cout << n << " rings were sold\n";
		double bill = 0;
		long long mine = 0;

		for (long long N = 0; N < n; N++) {
			//BILLS WAY
			double first = 0.25;
			bill += first + (N*10);

			// MY WAY
		 long long FIRST = 25;
			mine += FIRST + (N*1000);
		}
		std::cout << "Bill's program outputs " << std::fixed << std::setprecision(2) << bill << "\n";
		std::cout << "The exact profit is    " << std::fixed << std::setprecision(2) << (mine/100) << "." << (mine%100)<< "\n";

		
	}
}