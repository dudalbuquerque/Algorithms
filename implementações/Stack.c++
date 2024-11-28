//LIFO (Last In, First Out)
#include <iostream>
using namespace std;

typedef struct link {
    int element;
    link* next;
} Link;

typedef struct stack {
    Link* top;
    int size;
} Stack;

Link* create_link(int it, Link* nextval) {
    Link* n = new Link;
    n->element = it;
    n->next = nextval;
    return n;
}

Stack* create_stack() {
    Stack* s = new Stack;
    s->top = nullptr;
    s->size = 0;
    return s;
}

void push(Stack* s, int it) {
    s->top = create_link(it, s->top);
    s->size++;
}

int pop(Stack* s) {
    if (s->top == nullptr) {
        return -1; // Stack underflow
    }
    int it = s->top->element;
    Link* v_pop = s->top;
    s->top = s->top->next;
    delete v_pop;
    s->size--;
    return it;
}

int topValue(Stack* s) {
    if (s->top == nullptr) {
        return -1; 
    }
    return s->top->element; 
}

void clear(Stack* s) {
    while (s->top != nullptr) {
        pop(s); 
    }
}

int length(Stack* s) {
    return s->size; 
}

int main() {
    Stack* mystack = create_stack();

    int qnt_elements;
    cin >> qnt_elements;
    int valor;
    for (int i=0; i < qnt_elements; i++) {
        cin >> valor;
        push (mystack, valor);
    }

    cout << "Top value: " << topValue(mystack) << endl; 
    cout << "Stack length: " << length(mystack) << endl; 
  
    cout << "Popped: " << pop(mystack) << endl; 
    cout << "Popped: " << pop(mystack) << endl; 
  
    // Clear the stack
    clear(mystack);
    cout << "Stack length after clear: " << length(mystack) << endl; // Should print 0

    delete mystack; // Free allocated memory
    return 0;
}
