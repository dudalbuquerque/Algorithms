#include <iostream>
#include <string>
using namespace std;


struct BSTNode {
    int key;
    int element;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* create_bstnode(int k, int e) {
    BSTNode* n = new BSTNode;
    n->key = k;
    n->element = e;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

struct BST{
    BSTNode* root;
    int nodecount;
};

BST* create_bst(){
    BST* bst = new BST;
    bst->root = nullptr;
    bst->nodecount=0;
    return bst;
}

int findhelp(BSTNode* rt, int k) {
    if (rt == nullptr) {
        return -1;
    }
    if (rt->key > k) {
        return findhelp(rt->left, k);
    } else if (rt->key == k) {
        return rt->element;
    } else {
        return findhelp(rt->right, k);
    }
}

int find(BST* bst, int k) {
    return findhelp(bst->root, k);
}

BSTNode* inserthelp(BSTNode* rt, int k, int e) {
    if (rt == nullptr) {
        return create_bstnode(k, e);
    }
    if (rt->key > k) {
        rt->left = inserthelp(rt->left, k, e);
    } else {
        rt->right = inserthelp(rt->right, k, e);
    }
    return rt;
}
void insert(BST* bst, int k, int e) {
    bst -> root = inserthelp(bst -> root, k, e);
    bst->nodecount++;
}
void preorder(BSTNode* rt){
    if (rt != nullptr){
        cout << " " << rt->key;
        preorder(rt->left);
        preorder(rt->right);
    }
}
void inorder(BSTNode* rt){
    if (rt != nullptr){
      inorder(rt->left);
      cout << " " << rt->key;
      inorder(rt->right);
    }
}
void posorder(BSTNode* rt){
    if (rt != nullptr){
      posorder(rt->left);
      posorder(rt->right);
      cout << " " << rt->key;
    }
}
void pre_order(BST* bst){
    cout << "Pre order :";
    preorder(bst->root);
    cout << endl;
}
void in_order(BST* bst){
     cout << "In order  :";
     inorder(bst->root);
     cout << endl;
}
void pos_order(BST* bst){
     cout << "Post order:";
     posorder(bst->root);
     cout << endl;
}

int main() {
    int n;
    cin >> n;

    BST* bst = create_bst();

    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi;
        insert(bst, pi, pi);
    }
    pre_order(bst);
    in_order(bst);
    pos_order(bst);


    return 0;
}
