#include <iostream>
using namespace std;

// Function for Hoare partition
int hoarePartition(int array[], int start, int end) {
    int pivot = array[start]; // Selects the pivot
    int i = start;           // Starting index
    int j = end + 1;         // Ending index

    do {
        do {
            i++;
        } while (i <= end && array[i] < pivot);
        
        do {
            j--;
        } while (array[j] > pivot);
        
        if (i < j) {
            swap(array[i], array[j]);
        }
    } while (i < j);
    
    swap(array[start], array[j]);
    return j; // Returns the pivot position
}

// Quicksort function
void quicksort(int array[], int start, int end) {
    if (start < end) {
        int s = hoarePartition(array, start, end); // Partition position
        quicksort(array, start, s - 1);            // Recursion for the left part
        quicksort(array, s + 1, end);              // Recursion for the right part
    }
}

int main() {
    int array[] = {5, 2, 1, 7, 0}; 
    int n = sizeof(array) / sizeof(array[0]); // Size of the array

    quicksort(array, 0, n - 1); 

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
