#include<bits/stdc++.h>
using namespace std;

class Car {
private:
	int fuelLevel;

public:
	Car(int level) {
		this->level = level;
	}
	friend class Driver;
};

class Driver {
public:
	void checkFuelLevel(Car &car) {
		cout << "Fuel level: " << car.fuelLevel << "%" << "\n";
	}
};

int main() {
	Car car(75);
	Driver driver;
	driver.checkFuelLevel(car);
	return 0;
}