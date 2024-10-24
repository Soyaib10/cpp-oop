#include<bits/stdc++.h>
using namespace std;

class Room {
private:
	double length;
	double breadth;
	double height;

public:
	// parameterized constructor to initialize variables
	Room(double length, double breadth, double height) {
		this->length = length;
		this->breadth = breadth;
		this->height = height;
	}

	double calculateArea() {
		return length * breadth;
	}

	double calculateVolume() {
		return length * breadth * height;
	}
};

// copy constructor
class CopyConstructor {
public:
	int x;
	CopyConstructor(int x) {
		this->x = x;
	}

	// ccopy constructor
	CopyConstructor(const CopyConstructor &obj) {
		x = obj.x;
	}

	void display() {
		cout << "x: " << x << "\n";
	}
};

int main() {
	Room room(10.2, 10.3, 10.4);
	cout << "area: " << room.calculateArea() << "\n";
	cout << "volume: " << room.calculateVolume() << "\n";

	// copy constructor area
	CopyConstructor obj1(10);
	CopyConstructor obj2 = obj1;
	obj1.display();
	obj2.display();
}