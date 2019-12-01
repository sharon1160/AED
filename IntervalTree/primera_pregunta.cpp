#include <iostream> 
using namespace std; 

// Structure to represent an interval 
struct Interval 
{ 
	int low, high; 
}; 

// Estructura para representar un nodo en el Árbol de búsqueda de intervalos
struct ITNode 
{ 
	Interval *i; // 'i' también podría ser una variable normal
	int max; 
	ITNode *left, *right; 
}; 

// Una función de utilidad para crear un nuevo nodo de árbol de búsqueda de intervalos
ITNode * newNode(Interval i) 
{ 
	ITNode *temp = new ITNode; 
	temp->i = new Interval(i); 
	temp->max = i.high; 
	temp->left = temp->right = NULL; 
}; 

// Una función de utilidad para insertar un nuevo nodo de árbol de búsqueda de intervalos
// Esto es similar a BST Insert. Aquí el bajo valor del intervalo
// se usa para mantener la propiedad BST
ITNode *insert(ITNode *root, Interval i) 
{ 
	// Caso base: el árbol está vacío, el nuevo nodo se convierte en raíz
	if (root == NULL) 
		return newNode(i); 

	// Obtener un valor bajo de intervalo en la raíz
	int l = root->i->low; 

	// Si el valor bajo de la raíz es menor, entonces el nuevo intervalo va a
    // subárbol izquierdo 
	if (i.low < l) 
		root->left = insert(root->left, i); 

	// De lo contrario, el nuevo nodo va al subárbol derecho.
	else
		root->right = insert(root->right, i); 

	// Actualiza el valor máximo de este ancestro si es necesario
	if (root->max < i.high) 
		root->max = i.high; 

	return root; 
} 

// Una función de utilidad para verificar si se superponen dos intervalos
bool doOVerlap(Interval i1, Interval i2) 
{ 
	if (i1.low <= i2.high && i2.low <= i1.high) 
		return true; 
	return false; 
} 

// La función principal que busca un intervalo dado i en un determinado
// Árbol de intervalos.
Interval *overlapSearch(ITNode *root, Interval i) 
{ 
	// Caso base, el árbol está vacío 
	if (root == NULL) return NULL; 

	// Si el intervalo se superpone con la raíz
	if (doOVerlap(*(root->i), i)) 
		return root->i; 

	// Si el hijo izquierdo de la raíz está presente y el máximo del hijo izquierdo es
    // mayor o igual al intervalo dado, entonces puedo
    // la superposición con un intervalo se deja subárbol
	if (root->left != NULL && root->left->max >= i.low) 
		return overlapSearch(root->left, i); 

	// El otro intervalo solo puede superponerse con el subárbol derecho
	return overlapSearch(root->right, i); 
} 

void inorder(ITNode *root) 
{ 
	if (root == NULL) return; 

	inorder(root->left); 

	cout << "[" << root->i->low << ", " << root->i->high << "]"
		<< " max = " << root->max << endl; 

	inorder(root->right); 
} 

// Programa de controlador para probar las funciones anteriores
int main() 
{ 
	// Creemos el árbol de intervalos que se muestra en la figura anterior
	Interval intervalos[] = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40} }; 
	int n = sizeof(intervalos)/sizeof(intervalos[0]); 
	ITNode *root = NULL; 
	for (int i = 0; i < n; i++) 
		root = insert(root, intervalos[i]); 

	cout << "El recorrido transversal del árbol de intervalo construido es:"<<endl; 
	inorder(root); 

	Interval x = {6, 7}; 

	cout << "Buscando intervalo [" << x.low << "," << x.high << "]"<<endl; 
	Interval *res = overlapSearch(root, x); 
	if (res == NULL) 
		cout << "Sin intervalo de superposición"<<endl; 
	else
		cout << "Se superpone con [" << res->low << ", " << res->high << "]"<<endl; 
	return 0; 
}
