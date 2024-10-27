#include <bits/stdc++.h>
using namespace std;

class Human {
private:
    int age;
    string name;

public:
    Human(int age, string name) {
        setAge(age);  // Constructor-এও validation করতে চাই
        this->name = name;
    }

    void setAge(int age) {
        if (age >= 0 && age <= 150) { // বয়সের জন্য নিয়ন্ত্রণ
            this->age = age;
        } else {
            cout << "Invalid age! Setting default age to 0.\n";
            this->age = 0; // অবৈধ হলে 0 সেট করে দিচ্ছি
        }
    }

    int getAge() const {
        return age;
    }

    string getName() const {
        return name;
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << "\n";
    }
};

class Student : public Human {
private:
    int grade;

public:
    Student(int age, string name, int grade) : Human(age, name) {
        this->grade = grade;
    }

    void setGrade(int grade) {
        if (grade >= 1 && grade <= 12) {
            this->grade = grade;
        } else {
            cout << "Invalid grade! Setting default grade to 1.\n";
            this->grade = 1;
        }
    }

    int getGrade() const {
        return grade;
    }

    void display() const {
        cout << "Name: " << getName() << ", Age: " << getAge() << ", Grade: " << grade << "\n";
    }
};

int main() {
    Human human(-5, "John"); // অবৈধ বয়স সেট করায় 0 সেট হবে
    human.display();

    Student student(25, "Alice", 13); // অবৈধ গ্রেড সেট করায় ডিফল্ট 1 হবে
    student.display();

    student.setAge(200); // অবৈধ বয়স সেট করায় 0 হবে
    student.setGrade(8); // বৈধ গ্রেড সেট করায় 8 থাকবে
    student.display();

    return 0;
}
