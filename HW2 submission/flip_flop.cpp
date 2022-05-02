// Elana Lapins - Homework 2 Problem 0: Flip Flop
// Programming for Engineers, due: 09/17/2021

#include<iostream>
#include<string>

void main() {
	//INPUTS:
	int start = 0; // seconds to start at 
	int sec = 0; // # of seconds
	int a = 0; // a (flip)
	int b = 0; // b (flop)

	int cases = 0; 
	std::cin >> cases; //gets first value as num of cases

	for (int i = 0; i < cases; i++) {
		std::cout << "Case " << i << ":\n";

		for (int S = 0; S < cases; S += 3) {
			std::cin >> start;
		}
		for (int SEC = 1; SEC < cases; SEC += 3) {
			std::cin >> sec;
		}
		for (int A = 2; A < cases; A += 3) {
			std::cin >> a;
		}
		for (int B = 3; B < cases + 1; B+= 3) {
			std::cin >> b;
		}

		for (int w = start; w < start + sec; w++) {
			if (w% a == 0 && w % b == 0) {
				std::cout << "flipflop\n";
			}
			else if (w % a == 0) {
				std::cout << "flip\n";
			}
			else if (w % b == 0) {
				std::cout << "flop\n";
			}
			else {
				std::cout << w <<"\n";
			}
		}
		
	}
}