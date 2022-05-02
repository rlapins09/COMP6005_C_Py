// Elana Lapins - Homework 3 Problem 3: Root finding
// Programming for Engineers, due: 09/24/2021

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

double equation(double x) {
	double ans = pow(x, 5) + (6 * pow(x, 4)) + (3 * pow(x, 3)) - x - 50;
	return ans;
}

double f_prime(double x) {
	double deriv = (5 * pow(x, 4)) + (24 * pow(x, 3)) + (9 * pow(x, 2)) - 1;
	return deriv;
}


int main() {
	int cases = 0;
	std::cin >> cases;
	double x[3];
	double n = 0;
	double tolx = 0;

	for (int i = 0; i < cases; i++) {
		std::cout << "Case " << i << ":\n";
		int count = 0;
		double next = 0;
		double x_knot = 0;
		double error = 0;

		for (int j = 0; j < 3; j++) {
			std::cin >> x[j];
			//VARIABLES:
			x_knot = x[0];
			n = x[1];
			tolx = x[2];
		}

		for (int jj = 0; jj < n; jj++) {
			next = x_knot - (equation(x_knot) / f_prime(x_knot));
			error = abs((next - x_knot) / next);

			if (error >= tolx) {
				x_knot = next;
				count = jj + 1;
			}
			else {
				count = jj + 1;
				break;
			}
			
		}

		std::cout << std::setprecision(6) << "root at x = " << x_knot << " with error " << error << " after " << count << " iterations\n";

	}

}