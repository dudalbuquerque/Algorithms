#include <iostream>
#include <cstring>
using namespace std;

typedef struct link{
    int element;
    link* next;
} Link;

typedef struct queue{
    Link* front;
    Link* rear;
    int size;
}Queue;

Link* create_link(int it, Link* nextval) {
    Link* n = new Link;
    n->element = it;
    n->next = nextval;
    return n;
}
Link* create_next_link(Link* nextval) {
    Link* n = new Link;
    n -> next = nextval;
    return n;
}

Queue* create_queue(){
    Queue* q = new Queue;
    q -> front = q -> rear = create_next_link(nullptr);
    q -> size = 0;
    return q;
}

void enqueue(Queue* q, int it) {
    q -> rear -> next = create_link(it, nullptr);
    q -> rear = q -> rear -> next;
    q -> size++;
}

int dequeue(Queue* q){
    if (q -> size == 0) {
        return -1;
    }
    Link* temp = q-> front ->next;
    int it = q -> front -> next -> element;
    q -> front -> next = q -> front -> next -> next;
    if (q -> front -> next == nullptr) {
        q -> rear = nullptr;
    }
    delete temp;
    q -> size--;
    return it;
}

int main(){
    int qnt_casos;
    cin >> qnt_casos;
    
    for (int i=0; i < qnt_casos; i++) {
        Queue* myqueue = create_queue();
        
        int qnt_estudantes;
        cin >> qnt_estudantes;
        
        int li, ri;
        int temp_entrada = 1;
        
        for(int j = 0; j < qnt_estudantes; j++){
            cin >> li >> ri;
        
            if (li > temp_entrada){   //armazena o valor do primeiro estudante ao entrar na fila.
                temp_entrada = li; 
            }
            
            if (temp_entrada <= ri){
                enqueue(myqueue, temp_entrada);
                temp_entrada++;
            }else{
                enqueue(myqueue, 0);
            }
            
        }
        while(myqueue -> size > 0) {
            cout << dequeue(myqueue) << " ";
        }
        cout << endl;
        
    }
    return 0;
}
