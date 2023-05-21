#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void removeWhitespaces(string& str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

int main() {
    string inputFileName, outputFileName;

    cout << "Enter the name of the input file: ";
    cin >> inputFileName;

    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error opening input file: " << inputFileName << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Error opening output file: " << outputFileName << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {

        removeWhitespaces(line);

        outputFile << line;
    }

    inputFile.close();
    outputFile.close();

    cout << "Contents of " << inputFileName << " copied to " << outputFileName << " after removing whitespaces." << endl;

    return 0;
}