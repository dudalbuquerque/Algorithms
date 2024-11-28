// Abstract Data Type
/* 
Menu:
1. create_list - Function to create a new list.
2. insert - Function to insert an item into the list at the current position.
3. remove - Function to remove the item at the current position from the list.
4. movetostart - Function to move the cursor to the start of the list.
5. next - Function to move the cursor to the next element in the list.
*/

#include <iostream>
using namespace std;

template<typename E>
struct List {
    int maxSize;   
    int listSize;  
    int curr;       // Index of the current cursor position
    E* listArray;   
};

// Function to create the list
template<typename E>
List<E>* create_list(int size) {
    List<E>* l = new List<E>; // Allocate a new list
    l->maxSize = size;        
    l->listSize = l->curr = 0; 
    l->listArray = new E[size]; 
    return l; 
}

template<typename E>
void insert(List<E>* l, E item) {
    if (l->listSize >= l->maxSize) {  
        cout << "List is full!" << endl;
        return;
    }
    for (int i = l->listSize; i > l->curr; --i) {
        l->listArray[i] = l->listArray[i - 1];
    }
    l->listArray[l->curr] = item;  
    l->listSize++; 
}

template<typename E>
void remove(List<E>* l) {
    if (l->listSize == 0) {  // Check if the list is empty
        cout << "List is empty!" << endl;
        return;
    }
    for (int i = l->curr; i < l->listSize - 1; ++i) {
        l->listArray[i] = l->listArray[i + 1];
    }
    l->listSize--; 
}

template<typename E>
void movetostart(List<E>* l) {
    l->curr = 0; // Set the cursor to the start
}

template<typename E>
void next(List<E>* l) {
    if (l->curr < l->listSize - 1) {  
        l->curr++;
    }
}

int main() {
    List<int>* myList = create_list<int>(5); 

    insert(myList, 10);
    insert(myList, 20);
    insert(myList, 30);
    
    cout << "List after inserts:" << endl;
    for (int i = 0; i < myList->listSize; ++i) {
        cout << myList->listArray[i] << " ";
    }
    cout << endl;

    movetostart(myList); // Move the cursor to the start of the list
    remove(myList);      
  
    cout << "List after removal:" << endl;
    for (int i = 0; i < myList->listSize; ++i) {
        cout << myList->listArray[i] << " ";
    }
    cout << endl;

    next(myList);
    cout << "Current element: " << myList->listArray[myList->curr] << endl;

    // Free allocated memory
    delete[] myList->listArray; 
    delete myList;             
    return 0;
}
