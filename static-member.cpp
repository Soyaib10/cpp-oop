#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class StaticMemeber {
private:
	static int a;
	int b;

public:
	StaticMemeber() {
		a++;
	}

	StaticMemeber(int b) {
		this->b = b;
	}
	static int display() {
		return a;
	}
};

int StaticMemeber :: a = 0;

int main() {
	StaticMemeber obj1, obj2(1);
	cout << obj1.display() << "\n";
	cout << obj2.display();
    return 0;
}