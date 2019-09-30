/* Implementando iteradores y la clase set en
un BST*/

#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    struct Node *left, *right ; 
}; 
  
// función para almacenar los nodos en conjunto mientras
// se hace un recorrido transversal.
void storeinorderInSet(Node* root, set<int>& s) 
{ 
    if (!root) 
        return; 
    // visita el primer subárbol izquierdo
    storeinorderInSet(root->left, s); 
    // la inserción 
    s.insert(root->data);  
    // visita el subárbol derecho 
    storeinorderInSet(root->right, s); 
  
} 
  
// función para copiar elementos del conjunto uno por uno
// al árbol mientras se hace un recorrido transversal
void setToBST(set<int>& s, Node* root) 
{ 
    if (!root) 
        return; 
    setToBST(s, root->left); 
    auto it = s.begin(); 
    root->data = *it;  
    s.erase(it); 
    setToBST(s, root->right); 
  
}
  
// Convierte árbol binario en BST. 
void binaryTreeToBST(Node* root) 
{ 
    set<int> s; 
  
    storeinorderInSet(root, s); 

    setToBST(s, root); 
  
}
  
// función auxiliar para crear un nodo
Node* newNode(int data) 
{ 
    // asignación dinámica de memoria
    Node* temp = new Node(); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// función para hacer un recorrido transversal
void inorder(Node* root) 
{ 
    if (!root) 
        return; 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
} 
  
int main() 
{ 
    Node* root = newNode(5); 
    root->left = newNode(7); 
    root->right = newNode(9); 
    root->right->left = newNode(10); 
    root->left->left = newNode(1); 
    root->left->right = newNode(6); 
    root->right->right = newNode(11); 
    binaryTreeToBST(root); 
    cout<<"_____Arbol_____"<<endl;
    cout << "El recorrido transversal de BST es: " << endl; 
    inorder(root); 
    return 0; 
}
