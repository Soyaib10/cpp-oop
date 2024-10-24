#include <bits/stdc++.h>
using namespace std;

class Inline {
    int a;
    string s;

public:
    // Inline constructor
    Inline(int a, string s) : a(a), s(s) {
        // Constructor body (optional)
    }

    void display() {
        cout << "a: " << a << ", s: " << s << "\n";
    }
};

int main() {
    Inline obj(2, "sadf");
    obj.display(); // Output: a: 2, s: sadf

    return 0;
}
