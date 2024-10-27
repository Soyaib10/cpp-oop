#include <iostream>
using namespace std;

class MyClass {
public:
    char a;         // 1 byte
    int b;          // 4 bytes
    double c;       // 8 bytes
};

int main() {
    cout << "Size of MyClass: " << sizeof(MyClass) << " bytes" << endl;
    cout << "Alignment of char: " << alignof(char) << " bytes" << endl;
    cout << "Alignment of int: " << alignof(int) << " bytes" << endl;
    cout << "Alignment of double: " << alignof(double) << " bytes" << endl;
    return 0;
}
