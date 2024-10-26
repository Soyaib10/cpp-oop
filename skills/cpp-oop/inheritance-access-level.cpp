#include<bits/stdc++.h>
using namespace std;

class Human {
private:
	int age;
	string name;

public:
	Human(int age, string name) {
		this->age = age;
		this->name = name;
	}

	int getAge() {
		return age;
	}

	string getName() {
		return name;
	}

	void display() {
		cout << age << " " << name << "\n";
	}
};

class Student : public Human {
	// age, name are private to this class. 
	private:
		int grade;

	public:
		Student(int age, string name, int grade) : Human(age, name) {
			this->grade = grade;
		}

		void display() {
			cout << getAge() << " " << getName() << " " << grade << "\n";
		}
};

int main() {
	Human human(23, "Human");
	human.display();

	Student student(24, "Student", 7);
	student.display();
    return 0;
}