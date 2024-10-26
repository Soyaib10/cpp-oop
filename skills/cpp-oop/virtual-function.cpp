#include<bits/stdc++.h>
using namespace std;

// can not say Animal obj; obj = new Animal because it is a abstract class
// class Animal {
// public:
// 	virtual void display() = 0;
// };

// can make Animal obj; obj = new Animal
class Animal {
public:
	void display() {
		cout << "Animal\n";
	}
};

class Dog : public Animal {
public:
	void display() {
		cout << "Dog\n";
	}
};

class Cat : public Animal {
public:
	void display() {
		cout << "Cat\n";
	}
};

int main() {
    Animal *obj;
    obj = new Cat; // dispalys
    obj->display();
}