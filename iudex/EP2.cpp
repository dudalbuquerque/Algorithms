#include <iostream>
#include <cstring>
using namespace std;

typedef struct link {
    long long int element;
    link* next;
} Link;

typedef struct {
    Link* head;
    Link* tail;
    Link* curr;
    long long int cnt;
} List;

Link* create_link(long long int it, Link* nextval) {
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

void insert(List* l,long long int it) {
    l->curr->next = create_link(it, l->curr->next);
    if (l->tail == l->curr) {
        l->tail = l->curr->next;
    }
    l->cnt++;
}

void next(List* l) {
    if (l->curr != l->tail) {
        l->curr = l->curr->next;
    }
}

long long int remove1(List* l, int valor) {
    if (l -> curr -> next == nullptr) {
        return -1;
    }
    int it = l -> curr -> next -> element;
    l -> curr -> next = l -> curr -> next -> next;
    l -> cnt--;
    return it;
}

long long int getValue(List* l) {
    if (l->cnt != 0 && l->curr-> next != nullptr) {
        return l-> curr -> next -> element;
    } else {
        return -1;
    }
}
void MoveToStart(List* l){
    l -> curr = l -> head;
} 
void MoveToEnd(List* l){
    l -> curr = l -> tail;
} 
int main() {
    string comando;
    cin >> comando;
    long long int id;
    List* mylist = create_list();
    int cont_solve = 0;
    int cont_not_solve = 0;
    while(comando != "end") {
        if (comando == "add") {
            cin >> id;
            MoveToEnd(mylist);
            insert(mylist, id);
            next(mylist);
            cont_not_solve++;
        }
        else if (comando == "solve") {
            if(mylist -> cnt != 0){
                cont_solve++;
                cont_not_solve--;
                MoveToStart(mylist);
                int r = remove1(mylist, id);
            }
            
            
        }
        else if (comando == "stats") {
            cout << cont_solve << " " << cont_not_solve;
            cout << endl;
        }
        else if (comando == "print") {
            if(mylist -> cnt == 0){
                cout << "x";
            }
            
            MoveToStart(mylist);
            while(mylist -> curr -> next !=nullptr) {
                if (mylist -> curr -> next -> next == nullptr){
                    cout << getValue(mylist);
                }
                else{
                    cout << getValue(mylist) << " ";
                }
                next(mylist);
            }
            cout << endl;
        }
        
        cin >> comando;
    }
    return 0;
}