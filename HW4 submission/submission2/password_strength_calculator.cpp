#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<vector>
#include<cmath>

int find_strength(std::string password) {
	int total_strength, rules;
	bool a,b,c,d;

	size_t strength = password.length();
	rules = 0;

	//lowercase?
	a = std::any_of(password.begin(), password.end(), islower);
	if (a == true) {
		strength = strength + 1;
		rules = rules + 1;
	}
		
	//uppercase?
	b = std::any_of(password.begin(), password.end(), isupper);
	if (b == true) {
		strength = strength + 1;
		rules = rules + 1;
	}

	// numbers?
	c = std::any_of(password.begin(), password.end(), isdigit);
	if (c == true) {
		strength = strength + 1;
		rules = rules + 1;
	}

	// punctuation?
	d = std::any_of(password.begin(), password.end(), ispunct);
	if (d == true) {
		strength = strength + 2;
		rules = rules + 1;
	}

	if (rules > 1) {
		total_strength = strength * pow(2, rules - 1);
	}
	else {
		total_strength = strength;
	}
	return total_strength;
}


int main() {
	int cases;
	std::cin >> cases;
	std::string password;

	for (int i = 0; i < cases; i++) {
		std::cout << "Case " << i << ":\n";
		std::cin >> password;
		std::cout << "Strength: "<< find_strength(password) << "\n";
	}
}