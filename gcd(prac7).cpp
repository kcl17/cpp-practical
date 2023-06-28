#include <iostream>
using namespace std;

// Function to calculate GCD using recursion
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcdRecursive(b, a % b);
}

// Function to calculate GCD without recursion
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // Getting input from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Calculating GCD using recursion
    int gcdRec = gcdRecursive(num1, num2);
    cout << "GCD (Recursive): " << gcdRec << endl;

    // Calculating GCD without recursion
    int gcdItr = gcdIterative(num1, num2);
    cout << "GCD (Iterative): " << gcdItr << endl;

    return 0;
}
