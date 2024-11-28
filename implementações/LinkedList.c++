#include <iostream>
using namespace std;

// CREATING LINKED LIST

typedef struct node { // Structure to represent the nodes of the list
    int element;  // Node value
    node* next;   // Pointer to the next node
} Node;

typedef struct { 
    Node* head;  
    Node* tail;   
    Node* curr;   
    int cnt;      
} List;

Node* create_node(int it, Node* nextval) { 
    Node* newNode = new Node; 
    newNode->element = it;    
    newNode->next = nextval;  
    return newNode;         
}

Node* create_next_node(Node* nextval) { 
    Node* newNode = new Node; 
    newNode->next = nextval;  
    return newNode;          
}

List* create_list() { 
    List* list = new List; 
    list->curr = list->tail = list->head = create_next_node(nullptr); 
    list->cnt = 0; 
    return list;   
}

// OPERATIONS
void insert(List* list, int it) {
    list->curr->next = create_node(it, list->curr->next); 
    if (list->tail == list->curr) {
        list->tail = list->curr->next;
    }
    list->cnt++; 
}

void moveToStart(List* list) {
    list->curr = list->head; 
}

void prev(List* list) {
    if (list->curr == list->head) { return; } 
    Node* temp = list->head; // Temporary pointer to traverse the list
    while (temp->next != list->curr) {
        temp = temp->next; // Move temp to the previous node
    }
    list->curr = temp; // Update current to previous node
}

void next(List* list) {
    if (list->curr != list->tail) { 
        list->curr = list->curr->next; 
    }
}

int remove1(List* list) { 
    if (list->curr == list->tail) { // Check if current is at the tail
        return -1; 
    }
    int it = list->curr->next->element; 
    list->curr->next = list->curr->next->next; 
    list->cnt--;
    return it; 
}

int getValue(List* list) {
    if (list->cnt != 0) { 
        return list->curr->next->element; // Return the value of the current node
    } else {
        return -1; // Return -1 if the list is empty
    }
}

int main() {
    List* myList = create_list(); 
    int elementCount; 
    cin >> elementCount; 
    int value; 
    
    // Insert values into the list
    for (int i = 0; i < elementCount; i++) {
        cin >> value; 
        insert(myList, value); 
    }

    while (myList->curr->next != nullptr) {
        cout << getValue(myList) << " "; 
        next(myList); 
    }

    return 0;
}
/*
Menu:
1. create_list - Function to create a new linked list.
2. insert - Function to insert an element into the linked list at the current position.
3. remove - Function to remove the element at the current position from the linked list.
4. moveToStart - Function to move the cursor to the start of the linked list.
5. prev - Function to move the cursor to the previous element in the linked list.
6. next - Function to move the cursor to the next element in the linked list.
7. getValue - Function to get the value of the element at the current position in the linked list.
8. printList - Function to print all elements in the linked list.
9. exit - Function to exit the program.
*/

