#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class A {
public:
    int a;
    A(int a) {
        this->a = a;
    }
    void display() {
        cout << "A: " << a << "\n";
    }
};

class B {
public:
    int b;
    B(int b) {
        this->b = b;
    }
    void display() {
        cout << "B: " << b << "\n";
    }
};

class C : public A, public B {
public:
    int c;
    // C-এর কনস্ট্রাক্টর A এবং B-কে ইনিশিয়ালাইজ করবে
    C(int a, int b, int c) : A(a), B(b) {
    	this->c = c;
    }

    void display() {
        A::display(); // A-এর display() কল
        B::display(); // B-এর display() কল
        cout << "C: " << c << "\n"; // C-এর a-এর display
    }
};

int main() {
    C c(1, 2, 3); // A-র জন্য 1, B-র জন্য 2, C-র জন্য 3 প্রদান করা হলো
    c.display(); // সব ক্লাসের display() কল করবে
    return 0;
}
