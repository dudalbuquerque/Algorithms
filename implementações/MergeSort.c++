#include <iostream>
using namespace std;

void merge(int A[], int temp[], int left, int right) {
    for (int i = left; i <= right; i++) {
        temp[i] = A[i];
    }

    int mid = (left + right) / 2; 
    int i1 = left;              
    int i2 = mid + 1;            

    
    for (int curr = left; curr <= right; curr++) {
        if (i1 == mid + 1) {         
            A[curr] = temp[i2++];    
        } else if (i2 > right) {     
            A[curr] = temp[i1++];    
        } else if (temp[i1] <= temp[i2]) { 
            A[curr] = temp[i1++];   
        } else {
            A[curr] = temp[i2++];   
        }
    }
}

// Recursive Mergesort function (DIVIDE AND CONQUER)
void mergesort(int A[], int temp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;     
        mergesort(A, temp, left, mid);     
        mergesort(A, temp, mid + 1, right); 
        merge(A, temp, left, right);        
    }
}

int main() {
    int A[] = {5, 2, 1, 7, 0}; 
    int n = sizeof(A) / sizeof(A[0]); 

    int temp[n];  

    mergesort(A, temp, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
