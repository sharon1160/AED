#include <iostream> 
#include "dsexceptions.h"
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<vector>

using namespace std;

// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

class AvlNode
{
    public:
        int element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;
        AvlNode( const int & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
        : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
        
        AvlNode( int && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
        : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
        ~AvlNode(){};
        int contHijos(AvlNode * t){
            if(t->left!=nullptr){
                if(t->right!=nullptr){
                    return 2;
                }
            }
            else if(t->left!=nullptr){
                if(t->right==nullptr){
                    return 1;
                }
            }
            else if(t->right!=nullptr){
                if(t->left==nullptr){
                    return 1;
                }
            }
        }
        int calculaNodos (AvlNode* raiz, int contador){
            if( raiz->left != NULL)
                contador = calculaNodos(raiz->left,contador+1);
            if (raiz->right != NULL)
                contador =  calculaNodos (raiz->right, contador+1);
            return contador;
        }
};

class AvlTree
{
  public:
    AvlTree( ) : root{ nullptr }
      { 
          contador=0;
      }
    AvlTree( AvlTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    ~AvlTree( )
    {
        makeEmpty( );
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const int & x ) const
    {
        return contains( x, root );
    }

    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const int & findMin( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return findMin( root )->element;
    }
    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root );
    }

    void mostrar()
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else{
            mostrar( root ,contador);
        }
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const int & x )
    {
        insert( x, root );
        contador++;
    }
    
    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const int & x )
    {
        remove( x, root );
    }
    
    AvlNode* funcion(int h){
        if(h> root->height){//si la altura sobrepasa la altura del arbol bota error
            cout<<"error"<<endl;
        }
        else{
            findNodeH(h,root);//funcion para encontrar nodos con la altura h
            cout<<"Valor de la referencia: "<<findN(vec)->element<<endl;
            cout<<"La referencia : "<<findN(vec)<<endl;
            return findN(vec);
        }
    }
    
  private:

    int contador;
    AvlNode *root;
    int cont=0;
    vector<int> vec;

    void findNodeH (int h,AvlNode * t){//funcion para encontrar nodos con la altura h
        if(t != nullptr )
        {
            if(t->height!=h ){
                    findNodeH( h,t->left );
                    findNodeH( h,t->right );
            } 
            else if(t->height==h ){
                    vec.push_back(t->element);
                    cont++;
            }
        }
    }

    AvlNode* findN(vector<int> vector){
        int min=root->calculaNodos(root,2);
        AvlNode* clave=root;
        int count=0;
        while (count<cont){
                AvlNode * pt= contains2(vec[count],root);
                if(pt->calculaNodos(pt,0) < min){
                    min=pt->calculaNodos(pt,0);
                    clave=pt;
                }
                count++;
        }
        return clave;
    }

    AvlNode* contains2( const int & x, AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else if( x < t->element )
            return contains2( x, t->left );
        else if( t->element < x )
            return contains2( x, t->right );
        else
            return t;    // Match
    }
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const int & x, AvlNode * & t )
    {
        if( t == nullptr ){
            t = new AvlNode{ x, nullptr, nullptr };
        }
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        
        balance( t );
    }
    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const int & x, AvlNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing
        
        if( x < t->element )
            remove( x, t->left );
        else if( t->element < x )
            remove( x, t->right );
        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            AvlNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
        
        balance( t );
    }
    
    static const int ALLOWED_IMBALANCE = 1;

    // Assume t is balanced or within one of being balanced
    void balance( AvlNode * & t )
    {
        if( t == nullptr )
            return;
        
        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
            if( height( t->left->left ) >= height( t->left->right ) )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
        else
        if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
            if( height( t->right->right ) >= height( t->right->left ) )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );
                
        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    AvlNode * findMin( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        if( t->left == nullptr )
            return t;
        return findMin( t->left );
    }

    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    bool contains( const int & x, AvlNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;    // Match
    }
    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( AvlNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }
    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( AvlNode *t ) const
    {
        if( t != nullptr )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }
     
    void mostrar( AvlNode *t,int cont) const
    {
        if( t != nullptr )
        {
            mostrar( t->right, cont+1 );
            for(int i=0;i<cont;i++){
                cout<<"    ";
            }
            cout << t->element << endl;
            mostrar( t->left,cont+1 );
        }
    } 
        // Avl manipulations
    /**
     * Return the height of node t or -1 if nullptr.
     */
    int height( AvlNode *t ) const
    {
        return t == nullptr ? -1 : t->height;
    }

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }
    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild( AvlNode * & k2 )
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild( AvlNode * & k1 )
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild( AvlNode * & k3 )
    {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }

    /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
    void doubleWithRightChild( AvlNode * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }
};
    // Test program
int main( )
{
    AvlTree t;
    t.insert(5);
    t.insert(2);
    t.insert(1);
    t.insert(3);
    t.insert(8);
    t.insert(4);
    t.insert(9);
    t.insert(10);
    t.insert(11);
    t.insert(12);
    t.insert(6);
    t.insert(23);
    t.insert(24);
    t.insert(25);
    t.insert(26);
    t.insert(27);
    t.insert(28);
    t.insert(29);
    t.insert(30);
    t.funcion(4);
    return 0;
}
