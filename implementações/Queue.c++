//FIFO = first-in, first-out
#include <iostream>
using namespace std;

// Node structure for the linked list
typedef struct link {
    int element;      
    link* next;      
} Link;

// Queue structure
typedef struct queue {
    Link* front;     
    Link* rear;      
    int size;       
} Queue;

// Function to create a new link with a given value and next pointer
Link* create_link(int it, Link* nextval) {
    Link* n = new Link;
    n->element = it;
    n->next = nextval;
    return n;
}

Queue* create_queue() {
    Queue* q = new Queue;
    q->front = q->rear = create_link(0, nullptr); 
    q->size = 0;
    return q;
}

//add an element to the queue
void enqueue(Queue* q, int it) {
    q->rear->next = create_link(it, nullptr); // Create new link and add to the end
    q->rear = q->rear->next;                   // Update the rear pointer
    q->size++;                                  // Increment the size
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (q->size == 0) {
        return -1; // Queue is empty
    }
    int it = q->front->next->element;          // Get the front element
    q->front->next = q->front->next->next;    // Move front pointer to next
    if (q->front->next == nullptr) {
        q->rear = q->front;                    // Update rear if queue becomes empty
    }
    q->size--;                                  // Decrement the size
    return it;                                  // Return the removed element
}

// Function to get the value of the front element
int frontValue(Queue* q) {
    if (q->size == 0) {
        return -1;
    }
    return q->front->next->element;            
}

// Function to get the number of elements in the queue
int length(Queue* q) {
    return q->size;                            
}

void clear_queue(Queue* q) {
    while (q->size > 0) {
        dequeue(q); 
    }
}

int main() {
    Queue* myqueue = create_queue();

    int qnt_elements;
    cout << "Enter the number of elements to enqueue: ";
    cin >> qnt_elements;
    int valor;

    cout << "Enter the elements: ";
    for (int i = 0; i < qnt_elements; i++) {
        cin >> valor;
        enqueue(myqueue, valor); 
    }

    cout << "Front value: " << frontValue(myqueue) << endl; 
    cout << "Queue length: " << length(myqueue) << endl;    

    cout << "Dequeued elements: ";
    while (myqueue->size > 0) {
        cout << dequeue(myqueue) << " "; 
    }
    cout << endl;

    clear_queue(myqueue); 
    delete myqueue;      

    return 0;
}
