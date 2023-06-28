#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {}

    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
private:
    string course;
    double marks;
    int year;

public:
    Student(const string& n, const string& c, double m, int y) : Person(n), course(c), marks(m), year(y) {}

    void display() override {
        cout << "--- Student Details ---" << endl;
        Person::display();
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
        cout << "-----------------------" << endl;
    }
};

class Employee : public Person {
private:
    string department;
    double salary;

public:
    Employee(const string& n, const string& d, double s) : Person(n), department(d), salary(s) {}

    void display() override {
        cout << "--- Employee Details ---" << endl;
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    string name, course, department;
    double marks, salary;
    int year;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter course: ";
    getline(cin, course);

    cout << "Enter marks: ";
    cin >> marks;

    cout << "Enter year: ";
    cin >> year;
    cin.ignore();  // Ignore the newline character in the input buffer

    cout << "Enter department: ";
    getline(cin, department);

    cout << "Enter salary: ";
    cin >> salary;

    Person* person1 = new Person(name);
    Person* person2 = new Student(name, course, marks, year);
    Person* person3 = new Employee(name, department, salary);

    person1->display();
    person2->display();
    person3->display();

    delete person1;
    delete person2;
    delete person3;

    return 0;
}
