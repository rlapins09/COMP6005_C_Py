#include<iostream>
#include<string>

class MatrixInt {
public:
	int m, n;
	int* elements;

	//empty matrix constructor
	MatrixInt() : m{ 0 }, n{ 0 }, elements{ nullptr } {}; 

	//matrix constructor
	MatrixInt(int const m, int const n) : m{ m }, n{ n }, elements{ new int[m * n] }{};

	//matrix copy constructor
	MatrixInt(MatrixInt const& a) : m{ a.m }, n{ a.n }, elements{ new int[a.m * a.n] }
	{
		for (int i = 0; i < a.m * a.n; ++i) {
			elements[i] = a[i];
		}
		// matrix copy contructor
	}

	//deconstructor
	~MatrixInt() {
		delete[] elements;
	}


	//function overloading:
	MatrixInt& operator=(MatrixInt const& a) {

		//ADD: check if we are assigning to ourselves

		delete[] elements;

		m = a.m;
		n = a.n;
		int size = m * n;
		elements = new int[size];

		for (int i = 0; i < a.n * a.m; i++) {
			elements[i] = a[i];
		}
		return *this;
	}

	//single index element referencing
	int& operator[](int const idx) {
		return elements[idx];
	}

	//double index element referencing
	int& operator()(int const i, int const j) {

		int idx =   j + i*this->n;
		return elements[idx];

	}

	//single index const element referencing
	int const& operator[](int const idx) const {
		return elements[idx]; 
	}
	
	//double index const element referencing
	int const& operator()(int const i, int const j) const
	{
		int idx = j + i*this->n;
		return elements[idx];
	}

	//multiplication
	MatrixInt operator*(MatrixInt const& b) // multiplication
	{
		MatrixInt const& a = *this;
		MatrixInt mult_result{ a.m, b.n };

		for (int i = 0; i < a.m; i++) {
			for (int j = 0; j < b.n; j++) {
				mult_result(i,j) = 0;

				for (int k = 0; k < b.m; k++) {
					mult_result(i,j) += a(i,k) * b(k,j);
				}
			}
		}

		return mult_result; 
	}
	//addition
	MatrixInt operator+(MatrixInt const& b) {
		MatrixInt const& a = *this;
		MatrixInt add_result{ a.m, a.n };

		
		for (int i = 0; i < a.m; i++) {
			for (int j = 0; j < a.n; j++) {
				add_result(i, j) = a(i, j) + b(i, j);
			}
		}
		return add_result;
	}

};


// read function
	std::istream& operator>>(std::istream& os, MatrixInt& a)
	{
		int m, n;
		os >> m >> n;
		a = MatrixInt{ m, n };

		for (int i = 0; i < m * n; ++i) {
			os >> a[i];
		}

		return os;
	}

	//print function
	std::ostream& operator<<(std::ostream& os, MatrixInt const& a) {


		for (int i = 0; i < a.m; i++) {
			for (int j = 0; j < a.n; j++) {
				os << a(i,j) << " ";
			}
			os << std::endl;
		}
		return os;
	}



//////////DOUBLE///////////////
	class MatrixDouble {
	public:
		int m, n;
		double* elements;


		//empty matrix constructor
		MatrixDouble() : m{ 0 }, n{ 0 }, elements{ nullptr } {};

		//matrix constructor
		MatrixDouble(int const m, int const n) : m{ m }, n{ n }, elements{ new double[m * n] }{};

		//matrix copy constructor
		MatrixDouble(MatrixDouble const& a) : m{ a.m }, n{ a.n }, elements{ new double[a.m * a.n] }
		{
			for (int i = 0; i < a.m * a.n; ++i) {
				elements[i] = a[i];
			}
			// matrix copy contructor
		}

		//deconstructor
		~MatrixDouble() {
			delete[] elements;
		}
		


		//function overloading:
		MatrixDouble& operator=(MatrixDouble const& a) {

			//ADD: check if we are assigning to ourselves

			if (this != &a) {
			
				delete[] elements;

			
				m = a.m;
				n = a.n;
				int size = m * n;
				elements = new double[size];

			for (int i = 0; i < a.n * a.m; i++) {
				elements[i] = a[i];
			}
			}

			return *this;
		}

		//single index element referencing
		double& operator[](int const idx) {
			return elements[idx];
		}

		//double index element referencing
		double& operator()(int const i, int const j) {

			int idx = j + i * this->n;
			return elements[idx];

		}

		//single index const element referencing
		double const& operator[](int const idx) const {
			return elements[idx];
		}

		//double index const element referencing
		double const& operator()(int const i, int const j) const
		{
			
			int idx = j + i * this->n;
			return elements[idx];
		}


		//multiplication
		MatrixDouble operator*(MatrixDouble const& b) // multiplication
		{
			MatrixDouble const& a = *this;
			MatrixDouble mult_result{ a.m, b.n };

			for (int i = 0; i < a.m; i++) {
				for (int j = 0; j < b.n; j++) {
					mult_result(i, j) = 0;

					for (int k = 0; k < b.m; k++) {
						mult_result(i, j) += a(i, k) * b(k, j);
					}
				}
			}

			return mult_result;
		}
		//addition
		MatrixDouble operator+(MatrixDouble const& b) {
			MatrixDouble const& a = *this;
			MatrixDouble add_result{ a.m, a.n };


			for (int i = 0; i < a.m; i++) {
				for (int j = 0; j < a.n; j++) {
					add_result(i, j) = a(i, j) + b(i, j);
				}
			}
			return add_result;
		}


};

// read function
std::istream& operator>>(std::istream& os, MatrixDouble& a)
{
	int m, n;
	os >> m >> n;
	a = MatrixDouble{ m, n };

	for (int i = 0; i < m * n; ++i) {
		os >> a[i];
	}

	return os;
}

//print function
std::ostream& operator<<(std::ostream& os, MatrixDouble const& a) {


	for (int i = 0; i < a.m; i++) {
		for (int j = 0; j < a.n; j++) {
			os << a(i, j) << " ";
		}
		os << std::endl;
	}
	return os;
}


//////////MAIN///////////////

int main() {
	int case_count = 0;
	std::cin >> case_count;
	for (int i = 0; i < case_count; ++i) {
		std::cout << "Case " << i << ":\n";

		std::string operation;
		std::cin >> operation;
		std::string type;
		std::cin >> type;
		if (type == "int") {
			MatrixInt a, b;
			std::cin >> a >> b;

			if (operation == "add") {
				std::cout << a + b;
			}
			else if (operation == "multiply") {
				std::cout << a * b;
			}
		}
		else if (type == "double") {
			MatrixDouble  a, b;
			std::cin >> a >> b;

			if (operation == "add") {
				std::cout << a + b;
			}
			else if (operation == "multiply") {
				std::cout << a * b;
			}
		}
	}
}