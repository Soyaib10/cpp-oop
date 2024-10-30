#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string* name;
    int* roll;
    string* department;

public:
    // Normal Constructor
    Student(string n, int r, string d) {
        name = new string(n);
        roll = new int(r);
        department = new string(d);
        
        cout << "Normal Constructor কল হয়েছে" << endl;
    }
    
    // Copy Constructor
    Student(const Student& other) {
        // Deep Copy করছি
        name = new string(*other.name);
        roll = new int(*other.roll);
        department = new string(*other.department);
        
        cout << "Copy Constructor কল হয়েছে" << endl;
    }
    
    // Destructor
    ~Student() {
        delete name;
        delete roll;
        delete department;
    }
    
    // ছাত্রের তথ্য প্রিন্ট করার জন্য
    void printInfo() {
        cout << "নাম: " << *name << endl;
        cout << "রোল: " << *roll << endl;
        cout << "ডিপার্টমেন্ট: " << *department << endl;
    }
    
    // নাম পরিবর্তন করার জন্য
    void changeName(string newName) {
        *name = newName;
    }
};

// Pass by value (Copy Constructor কল হবে)
void displayStudent(Student s) {
    s.printInfo();
}

int main() {
    // প্রথম Student object তৈরি
    cout << "প্রথম ছাত্র তৈরি করছি:" << endl;
    Student student1("রহিম", 101, "CSE");
    cout << endl;
    
    // Copy Constructor ব্যবহার করে দ্বিতীয় Student তৈরি
    cout << "দ্বিতীয় ছাত্র তৈরি করছি (Copy Constructor):" << endl;
    Student student2 = student1;  // Copy Constructor called
    cout << endl;
    
    cout << "প্রথম ছাত্রের তথ্য:" << endl;
    student1.printInfo();
    cout << endl;
    
    cout << "দ্বিতীয় ছাত্রের তথ্য:" << endl;
    student2.printInfo();
    cout << endl;
    
    // প্রথম ছাত্রের নাম পরিবর্তন
    cout << "প্রথম ছাত্রের নাম পরিবর্তন করছি:" << endl;
    student1.changeName("করিম");
    cout << endl;
    
    cout << "পরিবর্তনের পর প্রথম ছাত্রের তথ্য:" << endl;
    student1.printInfo();
    cout << endl;
    
    cout << "পরিবর্তনের পর দ্বিতীয় ছাত্রের তথ্য:" << endl;
    student2.printInfo();
    cout << endl;
    
    // Function এ object pass করা (Copy Constructor কল হবে)
    cout << "Function এ ছাত্রের তথ্য পাঠাচ্ছি:" << endl;
    displayStudent(student1);
    
    return 0;
}