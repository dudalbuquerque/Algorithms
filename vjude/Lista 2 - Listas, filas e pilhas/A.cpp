#include <iostream>
#include <cstring>
using namespace std;

typedef struct link {
    char element;
    link* next;
} Link;

typedef struct {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
} List;

Link* create_link(char it, Link* nextval) {
    Link* n = new Link;
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_next_link(Link* nextval) {
    Link* n = new Link;
    n->next = nextval;
    return n;
}

List* create_list() {
    List* l = new List;
    l->curr = l->tail = l->head = create_next_link(nullptr);
    l->cnt = 0;
    return l;
}

void insert(List* l, char it) {
    l->curr->next = create_link(it, l->curr->next);
    if (l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void moveToStart(List* l) {
    l->curr = l->head;
}

void moveToEnd(List* l) {
    l->curr = l->tail;
}

void next(List* l) {
    if (l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

char getValue(List* l) {
    if (l->cnt != 0 && l->curr-> next != nullptr) {
        return l-> curr -> next -> element;
    } else {
        return -1;
    }
}

void clear(List* l) {
    l->curr = l->head;
    while (l->head != nullptr) {
        l->curr = l->head;
        l->head = l->head->next;
        delete l->curr;
    }
    l->head = l->tail = l->curr = create_next_link(nullptr);
    l->cnt = 0;
}

int main() {
    char frase[100001]; //+1 por conta do '\0'
    
    while(scanf("%s", frase) != EOF){
        List* mylist = create_list();
        int cont_print =0; 
        for (int i = 0;  frase[i] != '\0'; i++) {
            if (frase[i] == '[') {
                moveToStart(mylist);
            }
            else if(frase[i] == ']') {
                moveToEnd(mylist);
            }
            else{
                insert(mylist, frase[i]);
                next(mylist);
                cont_print++;
            }
        }
        moveToStart(mylist);
        for(int i=0; i<cont_print; i++){
            cout << getValue(mylist);
            next(mylist);
        }
        cout << endl;
        clear(mylist);
        delete mylist;
    }
    
    return 0;
}
