#include<bits/stdc++.h>
using namespace std;

class Room {
public:
	double length;
	double breadth;
	double height;

	double calculateArea() {
		return length * breadth;
	}

	double calculateVolume() {
		return length * breadth * height;
	}
};

int main() {
	Room room;
	room.length = 42.5;
	room.breadth = 30.8;
	room.height = 19.2;

	cout << "area: " << room.calculateArea() << "\n";
	cout << "volume: " << room.calculateVolume() << "\n";
}