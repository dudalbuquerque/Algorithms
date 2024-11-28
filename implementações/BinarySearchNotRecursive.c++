#include <iostream>
#include <cmath> // to use the floor function
using namespace std;

// Iterative binary search function
int binarySearch(int array[], int n, int target) {
    int left = 0;           
    int right = n - 1;     
  
    while (left <= right) {
        int mid = floor((left + right) / 2);  // Calculates the middle index

        if (array[mid] == target) {
            return mid;  // Return index if element is found
        }

        if (array[mid] > target) {
            right = mid - 1;  // Search in the left half
        }
        
        else {
            left = mid + 1;   // Search in the right half
        }
    }

    return -1; // Element not found
}

int main() {
    int array[] = {1, 3, 4, 7, 9, 11, 14};  // Sorted array
    int arraySize = 7;  // Array size
    int target = 7;     // Element we are searching for

    int result = binarySearch(array, arraySize, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
