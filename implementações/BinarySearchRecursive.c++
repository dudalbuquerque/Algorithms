#include <iostream>
using namespace std;

// Recursive binary search function
int binarySearch(int array[], int left, int right, int target) {
    if (right >= left) {
        int mid = (left + right) / 2;  // Calculates the middle index
        if (array[mid] == target) {
            return mid;  // Returns the index where the element is found
        }
        // Search in the left half
        if (array[mid] > target) {
            return binarySearch(array, left, mid - 1, target);
        }
        // Search in the right half
        return binarySearch(array, mid + 1, right, target);
    }
    return -1; // Element not found
}

int main() {
    int array[] = {1, 3, 4, 7, 9, 11, 14};  // Example array
    int arraySize = 7;  // Array size
    int target = 7;  // Element we are searching for

    int result = binarySearch(array, 0, arraySize - 1, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
