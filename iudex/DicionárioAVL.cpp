#include <iostream>
#include <string>
using namespace std;

class BSTNode {
public:
    int key;
    int element;
    BSTNode* left;
    BSTNode* right;
    int height;

    BSTNode(int k, int e){
        key = k;
        element = e;
        left = nullptr;
        right = nullptr;
        height = 0;
    }
};

class BST {
private:
    BSTNode* root;
    int nodecount;

    int h(BSTNode* rt) {
        if(rt == nullptr) {
            return -1;
        }
        return rt->height;
    }

    int getBalance(BSTNode* rt) {
        if (rt == nullptr) {
            return 0;
        }
        return h(rt->left) - h(rt->right);
    }

    BSTNode* rightRotate(BSTNode* rt) {
        BSTNode* l = rt -> left;
        BSTNode* lr = l -> right;
        l->right = rt;
        rt->left = lr;
        rt->height= max(h(rt->left), h(rt->right)) + 1;
        l->height= max(h(l->left), h(l->right)) + 1;
        return l;
    }
    BSTNode* leftRotate(BSTNode* rt) {
        BSTNode* r = rt ->  right;
        BSTNode* rl = r -> left;
        r->left = rt;
        rt->right = rl;
        rt->height= max(h(rt->left), h(rt->right)) + 1;
        r->height= max(h(r->left), h(r->right)) + 1;
        return r;
    }

    BSTNode* inserthelp(BSTNode* rt, int k, int e) {
        if (rt == nullptr) {
            return new BSTNode(k, e);
        }
        if (rt->key > k) {
            rt->left = inserthelp(rt->left, k, e);
        } else {
            rt->right = inserthelp(rt->right, k, e);
        }
        rt-> height = 1+ max(h(rt->left), h(rt->right));
        int balance=getBalance(rt);
        if(balance < -1 && k >= rt->right->key) {
            return leftRotate(rt);
        }
        if(balance > 1 && k < rt->left->key) {
            return rightRotate(rt);
        }
        if(balance > 1 && k >= rt->left->key) {
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if(balance < -1 && k < rt -> right->key) {
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
    }

public:
    BST() {
        root = nullptr;
        nodecount = 0;
    }
    void insert(int k, int e) {
        root = inserthelp(root, k, e);
        nodecount++;
    }

    void preorder(BSTNode* rt){
        if (rt != nullptr){
            cout << rt -> element << endl;
            preorder(rt->left);
            preorder(rt -> right);

        }
    }
    BSTNode* root1() {
        return root;
    }

};


int main(){
    int c;
    cin >> c; 
    
    for (int i = 0; i < c; i++){
        int n,s;
        cin >> n; 
        BST bst;
        for (int j = 0; j< n; j++){
            cin >> s;
            bst.insert(s, s);
        }
        bst.preorder(bst.root1());
        cout << "END" << endl;

    }
        
    return 0;
}