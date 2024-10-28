#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void openFile() {
	ofstream outFile; // Output file stream
    outFile.open("example.txt", ios::out); // Open file in write mode
    if (!outFile) {
        cout << "File couldn't be opened!" << endl;
        return;
    }
    outFile << "Hello, World!" << endl;
    outFile.close(); // Close the file
}

void writeFile() {
	ofstream outFile("example.txt", ios::out | ios::app); // Append mode
    if (!outFile) {
        cout << "File couldn't be opened!" << endl;
        return;
    }
    outFile << "Appending more data to the file." << endl;
    outFile.close();
}

void readFile() {
	ifstream inFile("example.txt", ios::in);
    if (!inFile) {
        cout << "File couldn't be opened!" << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) { // Read line by line
        cout << line << endl;
    }
    inFile.close();
}


int main() {
	readFile();
	return 0;
}


ios::in : পড়ার জন্য ফাইল খোলে।
ios::out : লেখার জন্য ফাইল খোলে।
ios::app : পূর্ববর্তী ডেটা রেখে নতুন ডেটা যুক্ত করে।
ios::trunc : পূর্ববর্তী ডেটা মুছে নতুন ডেটা লেখে।
ios::binary : বাইনারি মোডে ফাইল পড়া বা লেখা করে।
