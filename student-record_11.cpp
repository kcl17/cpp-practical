#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string className;
    int year;
    double totalMarks;

    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Class: ";
        getline(cin, className);

        cout << "Enter Year: ";
        cin >> year;

        cout << "Enter Total Marks: ";
        cin >> totalMarks;
    }

    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << className << endl;
        cout << "Year: " << year << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    ofstream outFile("students.txt");

    // Check if the file opened successfully
    if (!outFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Store 5 student objects in the file
    for (int i = 0; i < 5; i++) {
        Student student;
        cout << "Enter details for student " << i + 1 << ":" << endl;
        student.input();
        outFile.write(reinterpret_cast<char*>(&student), sizeof(student));
    }

    outFile.close();

    ifstream inFile("students.txt");

    // Check if the file opened successfully
    if (!inFile) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Read and display the student records from the file
    cout << "Student Records:" << endl;
    Student student;  // Declare the object here
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        student.display();
    }

    inFile.close();

    return 0;
}
