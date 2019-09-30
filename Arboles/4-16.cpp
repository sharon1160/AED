#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    Node(int d) {
        data = d;
        l = r = NULL;
    }
    int data;
    Node *l, *r;
};
class BST {
public:
    BST () {
        root = NULL;
    }
    ~BST () {
        destroy(root);
    }
    void destroy(Node *root) {
        if(root) {
            destroy(root->l);
            destroy(root->r);
            delete root;
        }
    }
    void insert(int e) {
        Node *p = root;
        Node *n = new Node(e);
        if(root == NULL) {
            root = n;
            return;
        }
        while(p) {
            if(e == p->data)
                return;
            if(e > p->data)
                if(!p->r) {
                    p->r = n;
                    return;
                }
                else
                    p = p->r;
            else if(!p->l) {
                p->l = n;
                return;
            }
            else
                p = p->l;
        }
    }

    Node* findMin(Node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->l == NULL){
            cout<<"El elemento minimo es : "<<t->data<<endl;
            return t;
        }
        else
            return findMin(t->l);
    }
    Node* findMax(Node* t) {
        if(t == NULL)
            return NULL;
        else if(t->r== NULL){
            cout<<"El elemento maximo es : "<<t->data<<endl;
            return t;
        }
        else
            return findMax(t->r);
    }
    Node* remove(int x, Node* t) {
        Node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->l = remove(x, t->l);
        else if(x > t->data)
            t->r = remove(x, t->r);
        else if(t->l && t->r)
        {
            temp = findMin(t->r);
            t->data = temp->data;
            t->r = remove(t->data, t->r);
        }
        else
        {
            temp = t;
            if(t->l == NULL)
                t = t->r;
            else if(t->r == NULL)
                t = t->l;
            delete temp;
        }
    
        return t;
    }
    void inorder(Node* t) {
        if(t == NULL)
            return;
        inorder(t->l);
        cout << t->data << " ";
        inorder(t->r);
    }
    
    Node* find(Node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->l, x);
        else if(x > t->data)
            return find(t->r, x);
        else
            return t;
    }
    Node *root;
};
int main() {

    BST tree;
    tree.insert(11);
    tree.insert(10);
    tree.insert(12);
    cout<<"_____Arbol____"<<endl;
    tree.inorder(tree.root);
    cout<< endl;
    tree.findMin(tree.root);
    tree.findMax(tree.root);
    return 0;
}
