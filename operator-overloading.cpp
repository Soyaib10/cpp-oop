#include <iostream>
using namespace std;

class Complex {
private:
	int real;
	int img;

public:
	Complex() {}
	Complex(int real, int img) : real(real), img(img) {}

	// Overloading the '+' operator
	Complex operator + (const Complex &obj) {
		Complex result;
		result.real = real + obj.real;
		result.img = img + obj.img;
		return result;
	}

	void display() {
		cout << real << " + " << img << "i" << "\n";
	}
};

int main() {
	Complex c1(3, 4);
	Complex c2(1, 2);

	Complex c3 = c1 + c2;  
	c3.display();

	return 0;
}
