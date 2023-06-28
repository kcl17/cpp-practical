#include <iostream>

using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0; // Index for arr1[]
    int j = 0; // Index for arr2[]
    int k = 0; // Index for merged[]

    // Merge elements from arr1[] and arr2[] in sorted order
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1[], if any
    while (i < size1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2[], if any
    while (j < size2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1, size2;

    cout << "Enter the size of the first array: ";
    cin >> size1;
    int arr1[size1];

    cout << "Enter the elements of the first array in ascending order(using spaces): ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of the second array: ";
    cin >> size2;
    int arr2[size2];

    cout << "Enter the elements of the second array in ascending order(using spaces): ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int merged[size1 + size2];

    mergeArrays(arr1, size1, arr2, size2, merged);

    cout << "Merged array: ";
    printArray(merged, size1 + size2);

    return 0;
}
