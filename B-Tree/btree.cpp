#include<iostream>
#include <vector>
using namespace std;

class Node
{
    int n;
    int t;
    bool leaf;
    vector <int> keys;
    vector <Node *> childs;
public:
    Node(int _t, bool _leaf);

    void insertNonFull(int k);
    void splitChild(int i, Node *y);
    void traverse();
    Node *search(int k);

friend class Tree;
};

class Tree
{
        Node *root;
        int t;
    public:
        Tree(int _t) {
            root = NULL;  t = _t;
        }

        void traverse() {
            if (root != NULL) root->traverse();
        }

        Node* search(int k) {
            return (root == NULL)? NULL : root->search(k);
        }

        Node* getRoot() {
            return root;
        }

        int minimum(Node *x);
        int maximum(Node *x);

        void insert(int k);

        friend class Node;
};

Node::Node(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;

    keys.reserve(2*t-1);
    childs.reserve(2*t);
    n = 0;
}

void Node::traverse() {


    int i;
    for (i = 0; i < n; i++)
    {
    	cout<<" ";
        if (leaf == false)
            childs[i]->traverse();

        cout << " " << keys[i];
    }

    if (leaf == false)
        childs[i]->traverse();

}

Node *Node::search(int k) {
    //Encontrar la primera clave mayor o igual a k
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    //Si la clave actual resulta ser deseada, se devolver�
    if (keys[i] == k)
        return this;

    //Si es una hoja y no se encuentra la clave, no est� en la estructura
    if (leaf == true)
        return NULL;

    return childs[i]->search(k);
}

void Tree::insert(int k) {


    if (root == NULL) {

        root = new Node(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else  {
        if (root->n == 2*t-1)
        {
            Node *s = new Node(t, false);

            s->childs[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->childs[i]->insertNonFull(k);

            //Cambiar ra�z
            root = s;
        }
        else  // Si la ra�z no est� llena, llame a insertNonFull para la ra�z
            root->insertNonFull(k);
    }
}

int Tree::minimum( Node *x) {
    return (x->leaf==true) ? x->keys[0] : minimum(x->childs[0]);
}

int Tree::maximum(Node *x) {
    return (x->leaf==true) ? x->keys[x->n-1] : maximum(x->childs[x->n]);
}

void Node::insertNonFull(int k) {
    int i = n-1;//�ndice del primer elemento correcto



    if (leaf == true) {
        // Este bucle deja espacio para una nueva clave
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            i--;
        }
        //agregando una llave
        keys[i+1] = k;
        n = n+1;
    }
    else {
        // Esta funci�n selecciona al ni�o a quien le insertar� un nuevo elemento
        while (i >= 0 && keys[i] > k)
            i--;

        if (childs[i+1]->n == 2*t-1) //cuando el ni�o est� lleno
        {
            splitChild(i+1, childs[i+1]); //se rompe

            if (keys[i+1] < k)
                i++;
        }
        childs[i+1]->insertNonFull(k); //recursividad en caso de que el nodo actual no sea
    }
}

void Node::splitChild(int i, Node *y)
{
    // Tworzymy nowy wezel do trzymania t-1 kluczy
    Node *z = new Node(y->t, y->leaf);
    z->n = t - 1;

    // kopiujemy ostatnia polowe kluczy z y do z
    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    // jesli wezel nie jest lisciem to kopiujemy ostatnia polowe jego dzieciak�w
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->childs[j] = y->childs[j+t];
    }

    y->n = t - 1; //w y jest teraz t-1 kluczy, bo bylo 2t-1, a usunelismy t

    //Robimy miejsce dla nowego dziecka
    for (int j = n; j >= i+1; j--)
        childs[j+1] = childs[j];

    //Tym dzieckiem bedzie z
    childs[i+1] = z;

    //robimy miejsce dla nowego klucza
    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    //srodkowy klucz zostanie przepisany do wezla
    keys[i] = y->keys[t-1];

    n = n + 1;
}

int main()
{
    Tree t(3);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "El recorrido del arbol construido es ";
    t.traverse();

    cout<<endl;
    int k = 6;
    if(t.search(k) != NULL)
         cout << "Presente"<<endl;
    else
        cout << "No presente"<<endl;

    k = 15;
    if(t.search(k) != NULL)
        cout << "Presente"<<endl;
    else
        cout << "No Presente"<<endl;

    return 0;
}
