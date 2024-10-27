#include <bits/stdc++.h>
using namespace std;

class DestructorCalling {
private:
    string s;
    int *data;

public:
	DestructorCalling(string s) {
		this->s = s;
		cout << "constructor is " << s << "\n"; 
	}

	~DestructorCalling() {
		cout << "destructor is " << s << "\n";
	}
};

int main() {
    DestructorCalling d1("1"), d2("2");

    return 0;
}
