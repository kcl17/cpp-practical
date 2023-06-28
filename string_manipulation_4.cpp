#include <iostream>
using namespace std;

void showAddress(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        cout << "Address of '" << str[i] << "': " << static_cast<const void*>(&str[i]) << endl;
    }
}

char* concatenateStrings(const char* str1, const char* str2) {
    int len1 = 0;
    while (str1[len1] != '\0')
        len1++;

    int len2 = 0;
    while (str2[len2] != '\0')
        len2++;

    char* result = new char[len1 + len2 + 1];

    int i, j;

    for (i = 0; i < len1; i++)
        result[i] = str1[i];

    for (j = 0; j < len2; j++)
        result[i + j] = str2[j];

    result[i + j] = '\0';

    return result;
}

int compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0')
            return 0;
        i++;
    }
    return str1[i] - str2[i];
}

int calculateStringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

void convertToLowercase(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
}

void reverseString(char* str) {
    int i = 0;
    int j = calculateStringLength(str) - 1;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

char* insertString(const char* str1, const char* str2, int position) {
    int len1 = calculateStringLength(str1);
    int len2 = calculateStringLength(str2);

    char* result = new char[len1 + len2 + 1];

    int i, j;

    for (i = 0; i < position; i++)
        result[i] = str1[i];

    for (j = 0; j < len2; j++)
        result[i + j] = str2[j];

    for (; i < len1; i++)
        result[i + len2] = str1[i];

    result[i + len2] = '\0';

    return result;
}

int main() {
    char str1[100], str2[100];
    int choice;

    while (true) {
        cout << "\nString Manipulation Menu:" << endl;
        cout << "1. Show address of each character in a string" << endl;
        cout << "2. Concatenate two strings" << endl;
        cout << "3. Compare two strings" << endl;
        cout << "4. Calculate length of a string" << endl;
        cout << "5. Convert lowercase characters to uppercase" << endl;
        cout << "6. Reverse a string" << endl;
        cout << "7. Insert a string in another string at a user specified position" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter a string: ";
                cin >> str1;
                showAddress(str1);
                break;
            }
            case 2: {
                cout << "Enter the first string: ";
                cin >> str1;
                cout << "Enter the second string: ";
                cin >> str2;
                char* concatResult = concatenateStrings(str1, str2);
                cout << "Concatenated string: " << concatResult << endl;
                delete[] concatResult;
                break;
            }
            case 3: {
                cout << "Enter the first string: ";
                cin >> str1;
                cout << "Enter the second string: ";
                cin >> str2;
                int compareResult = compareStrings(str1, str2);
                if (compareResult < 0)
                    cout << "String 1 is less than String 2" << endl;
                else if (compareResult > 0)
                    cout << "String 1 is greater than String 2" << endl;
                else
                    cout << "String 1 is equal to String 2" << endl;
                break;
            }
            case 4: {
                cout << "Enter a string: ";
                cin >> str1;
                int length = calculateStringLength(str1);
                cout << "Length of the string: " << length << endl;
                break;
            }
            case 5: {
                cout << "Enter a string: ";
                cin >> str1;
                convertToLowercase(str1);
                cout << "String in lowercase: " << str1 << endl;
                break;
            }
            case 6: {
                cout << "Enter a string: ";
                cin >> str1;
                reverseString(str1);
                cout << "Reversed string: " << str1 << endl;
                break;
            }
            case 7: {
                cout << "Enter the first string: ";
                cin >> str1;
                cout << "Enter the second string: ";
                cin >> str2;
                int position;
                cout << "Enter the position to insert: ";
                cin >> position;
                char* insertResult = insertString(str1, str2, position);
                cout << "Inserted string: " << insertResult << endl;
                delete[] insertResult;
                break;
            }
            case 8:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
