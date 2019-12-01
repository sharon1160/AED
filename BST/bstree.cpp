#include <iostream>

using namespace std;


struct Node{
	int value;
	Node *left;
	Node *right;
};

class btree{
public:
	btree(){
        root = NULL;
    }
	~btree(){
        destroy_tree();
    }
    void heightTree()
    {
        cout<<"La altura del arbol es: "<<heightTree(root)<<endl;
    }
    void heightNode(int dato1){
        cout<<"La altura del nodo es: "<<heightNode(search(dato1))<<endl;
    }
    int depthArbolNode (int dato){
        cout<<"La profundidad del nodo es: "<<depthArbolNode(root, dato)<<endl;
    }
    void hermanos(int dato1,int dato2){
        if(hermanos(dato1,dato2,root)==true)
            cout<<"Si son hermanos"<<endl;
        else
        {
            cout<<"No son hermanos"<<endl;
        }
        
    }

	void insert(int key){
        if(root != NULL){
            insert(key, root);
        }else{
            root = new Node;
            root->value = key;
            root->left = NULL;
            root->right = NULL;
        }
    }
    
	Node *search(int key){
        return search(key, root);
    }
	void destroy_tree(){
        destroy_tree(root);
    }
	void inorder_print(){
        inorder_print(root);
        cout <<endl;
    }
	void postorder_print(){
        postorder_print(root);
        cout <<endl;
    }
	void preorder_print(){
        preorder_print(root);
        cout <<endl;
    }

private:
    bool flag=false;
    bool hermanos(int dato1,int dato2,Node* root){
        if(root != NULL){
            if(dato1 == root->left->value && dato2 == root->right->value ){
                flag=true;
                return flag;
            }
            else if(dato2 == root->left->value && dato1 == root->right->value ){
                flag=true;
                return flag;
            }
            if(dato1 != root->left->value && dato2 == root->right->value ){
                flag=false;
                return flag;
            }
            if(dato1 == root->left->value && dato2 != root->right->value ){
                flag=false;
                return flag;
            }
            else if(dato2 == root->left->value && dato1 != root->right->value ){
                flag=false;
                return flag;
            }
            else if(dato2 != root->left->value && dato1 == root->right->value ){
                flag=false;
                return flag;
            }
            if(dato2 != root->left->value && dato1 != root->right->value){
                if(dato1 < root->value){
                    return hermanos(dato1,dato2, root->left);
                }else{
                    return hermanos(dato1,dato2, root->right);
                }
            }
        }else{
            flag=false;
            return flag;
        }
    }
    int depthArbolNode (Node* root, int dato){
        int depth=0;
        Node* actual=root;
        while (actual!=NULL){
            if (dato == actual->value){           
                return depth;
            }
            else{
                depth++;
                if (dato < actual->value){               
                    actual=actual->left;
                }else{
                    if (dato > actual->value){               
                        actual=actual->right;
                    }
                }
            }
        }
        return -1;
    }
    int heightNode(Node *dato1)
    {
        int AltIzq, AltDer;

        if(dato1==NULL)
            return -1;
        else
        {
            AltIzq = heightNode(dato1->left);
            AltDer = heightNode(dato1->right);

            if(AltIzq>AltDer)
                return AltIzq+1;
            else
                return AltDer+1;
        }
    }
    int heightTree(Node *root)
    {
        int AltIzq, AltDer;

        if(root==NULL)
            return -1;
        else
        {
            AltIzq = heightTree(root->left);
            AltDer = heightTree(root->right);

            if(AltIzq>AltDer)
                return AltIzq+1;
            else
                return AltDer+1;
        }
    }
	void destroy_tree(Node *root){
        if(root != NULL){
            destroy_tree(root->left);
            destroy_tree(root->right);
            delete root;
        }
    }
	void insert(int key, Node *root){
        if(key < root->value){
            if(root->left != NULL){
                insert(key, root->left);
            }else{
                root->left = new Node;
                root->left->value = key;
                root->left->left = NULL;
                root->left->right = NULL;
            }
        }else if(key >= root->value){
            if(root->right != NULL){
                insert(key, root->right);
            }else{
                root->right = new Node;
                root->right->value = key;
                root->right->right = NULL;
                root->right->left = NULL;
            }
        }

    }
	Node *search(int key, Node *root){
        if(root != NULL){
            if(key == root->value){
                return root;
            }
            if(key < root->value){
                return search(key, root->left);
            }else{
                return search(key, root->right);
            }
        }else{
            return NULL;
        }
    }
	void inorder_print(Node *root){
        if(root != NULL){
            inorder_print(root->left);
            cout << root->value << " ";
            inorder_print(root->right);
        }
    }
	void postorder_print(Node *root){
        if(root != NULL){
            inorder_print(root->left);
            inorder_print(root->right);
            cout << root->value << " ";
        }
    }
	void preorder_print(Node *root){
        if(root != NULL){
            cout << root->value << " ";
            inorder_print(root->left);
            inorder_print(root->right);
        }
    }

	Node *root;
};


int main(){

	//btree tree;
	btree *tree = new btree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);
    tree->insert(12);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

    cout<<endl;
    tree->heightTree();//retorna la altura de un arbol

    cout<<endl;
    tree->heightNode(14);//retorna la altura un nodo
	                       //retorna -1 si no existe el nodo
    cout<<endl;
    tree->depthArbolNode(14);//retornala profundidad de un nodo
                            //retorna -1 si no existe el nodo
    cout<<endl;
    int a,b;
    cout<<"a?"<<endl;
    cin>>a;
    cout<<"b?"<<endl;
    cin>>b;
    tree->hermanos(a,b);//retorna si son hermanos o no

    delete tree; 

}
