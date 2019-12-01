#include <bits/stdc++.h> 
using namespace std; 

// Una función para obtener el índice medio de los índices de esquina.
int getMid(int s, int e) { 
	return s + (e -s)/2; 
} 

// funcion	para	calcular	el	minimo	de	dos	numeros		 
int minVal(int x, int y) { 
	return (x < y)? x: y; 
} 


/* Una función recursiva para obtener el
valor mínimo en un rango dado
de índices de matriz. El seguimiento
son parámetros para esta función.

stree -> Puntero al árbol de segmentos
index -> Índice del nodo actual en el
árbol de segmentos Inicialmente 0 es
pasado como root siempre está en el índice 0
ss & se -> Índices iniciales y finales
del segmento representado
por nodo actual, es decir, st [índice]
qinicio & qfin -> Índices de inicio y finalización del rango de consulta */
int RMQUtil(int *stree, int ss, int se, int qinicio, int qfin, int index) 
{ 
	// Si el segmento de este nodo es una parte
	// del rango dado, luego regrese
	// el min del segmento 
	if (qinicio <= ss && qfin >= se) 
		return stree[index]; 

	// Si segmento de este nodo
	// está fuera del rango dado 
	if (se < qinicio || ss > qfin) 
		return INT_MAX; 

	// Si una parte de este segmento
	// se superpone con el rango dado
	int mid = getMid(ss, se); 
	return minVal(RMQUtil(stree, ss, mid, qinicio, qfin, 2*index+1), RMQUtil(stree, mid+1, se, qinicio, qfin, 2*index+2)); 
} 

// Devuelve un mínimo de elementos en el rango
// del índice qs (inicio de consulta) a
// qe (fin de la consulta). Utiliza principalmente MQUtil ()
int RMQ(int *stree, int n, int qinicio, int qfin) 
{ 
	// Verificar valores de entrada erróneos
	if (qinicio < 0 || qfin > n-1 || qinicio > qfin) 
	{ 
		cout<<"Rango invalido"; 
		return -1; 
	} 

	return RMQUtil(stree, 0, n-1, qinicio, qfin, 0); 
} 


/* Una función recursiva para obtener la suma de valores en el rango dado 
del arreglo. Los siguientes son parámetros para esta función.

stree -> Puntero al segment tree

nodoActual -> Índice del nodo actual en el segment tree.
Inicialmente 0 se pasa ya que la raíz siempre está en el índice 0

inicio & final -> Índices iniciales y finales del segmento 
representado por nodo actual, es decir, stree [nodoActual]

qinicio & qfinal -> Índices de inicio y finalización del rango de consulta */

int getSumUtil(int *stree, int inicio, int	final, int qinicio, int qfinal, int nodoActual) 
{ 
	// nodoActual el segmento de este nodo es parte del rango dado, entonces devuelve
	// la suma del segmento
	if (qinicio <= inicio && qfinal >= final) 
		return stree[nodoActual]; 

	// Si el segmento de este nodo está fuera del rango dado
	if (final < qinicio || inicio > qfinal) 
		return 0; 

	// Si una parte de este segmento se superpone con el rango dado
	int mid = getMid(inicio, final); 
	return getSumUtil(stree, inicio, mid, qinicio, qfinal, 2*nodoActual+1) + getSumUtil(stree, mid+1, final, qinicio, qfinal, 2*nodoActual+2); 
} 

/* Una función recursiva para actualizar los nodos que tienen el dado
índice en su rango. Los siguientes son parámetros

stree, nodoActual, inicio y final son los mismos que getSumUtil ()
i -> índice del elemento a actualizar. Este índice es en la matriz de entrada.
valor -> Valor a agregar a todos los nodos que tienen i en rango */
void updateValueUtil(int *stree, int inicio, int final, int i, int valor, int nodoActual) 
{ 
	// Caso base: si el índice de entrada se encuentra fuera del rango de
	// este segmento 
	if (i < inicio || i > final) 
		return; 

	// Si el índice de entrada está dentro del rango de este nodo, actualice
	// el valor del nodo y sus hijos
	stree[nodoActual] = stree[nodoActual] + valor; 
	if (final != inicio) 
	{ 
		int mid = getMid(inicio, final); 
		updateValueUtil(stree, inicio, mid, i, valor, 2*nodoActual + 1); 
		updateValueUtil(stree, mid+1, final, i, valor, 2*nodoActual + 2); 
	} 
} 

// La función para actualizar un valor en la matriz de entrada y el segment tree.
// Utiliza updateValueUtil () para actualizar el valor en el segment tree
void updateValue(int arr[], int *stree, int n, int i, int new_val) 
{ 
	// Comprueba si hay un índice de entrada erróneo 
	if (i < 0 || i > n-1) 
	{ 
		cout<<"Invalid Input"; 
		return; 
	} 

	// Obtenga la diferencia entre el valor nuevo y el valor antiguo 
	int valor = new_val - arr[i]; 

	// Actualizar el valor en la matriz 
	arr[i] = new_val; 

	// Actualiza los valores de los nodos en el árbol de segmentos 
	updateValueUtil(stree, 0, n-1, i, valor, 0); 
} 

// Devuelve la suma de elementos en el rango del índice qinicio (inicio de consulta)
// a qfinal (fin de la consulta). Utiliza principalmente getSumUtil ()
int getSum(int *stree, int n, int qinicio, int qfinal) 
{ 
	// Verificar valores de entrada erróneos 
	if (qinicio < 0 || qfinal > n-1 || qinicio > qfinal) 
	{ 
		cout<<"Rango invalido"; 
		return -1; 
	} 

	return getSumUtil(stree, 0, n-1, qinicio, qfinal, 0); 
} 

// Una función recursiva que construye el segment tree para la matriz [inicio..final].
// si es el índice del nodo actual en el segment tree stree
int constructSTUtil(int arr[], int inicio, int final, int *stree, int nodoActual) 
{ 
	// Si hay un elemento en la matriz, almacénelo en el nodo actual de
	// segmenta el árbol y regresa
	if (inicio == final) 
	{ 
		stree[nodoActual] = arr[inicio]; 
		return arr[inicio]; 
	} 

	// Si hay más de un elemento, entonces repite para left y
	// subárboles derechos y almacena la suma de valores
	int mid = getMid(inicio, final); 
	stree[nodoActual] = constructSTUtil(arr, inicio, mid, stree, nodoActual*2+1) + constructSTUtil(arr, mid+1, final, stree, nodoActual*2+2); 
	return stree[nodoActual]; 
} 

/* Función para construir un segment tree a partir de una matriz dada. Esta función
asigna memoria para el árbol de segmentos y llama a constructSTUtil () para
llenar la memoria asignada */
int *constructST(int arr[], int n) 
{ 
	// Asigna memoria para el árbol de segmentos

	// Altura del segment tree
	int x = (int)(ceil(log2(n))); //La función ceil () devuelve el valor entero 
								  //más pequeño posible que es mayor o igual que el argumento dado

	// Tamaño máximo del segment tree(num dw nodos)
	int max_size = 2*(int)pow(2, x) - 1; 

	// Asignar memoria 
	int *stree = new int[max_size]; 

	// Rellene la memoria asignada stree
	constructSTUtil(arr, 0, n-1,stree, 0); 

	// Devuelve el segment tree construido
	return stree; 
} 
// Programa de controlador para probar las funciones anteriores 
int main() 
{ 
	int arr[] = {1, 3, 5, 7, 9, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); //para obtener el tamaño

	// Construye un segment tree a partir de una matriz 
	int *stree = constructST(arr, n); 

	// Imprime la suma de valores en la matriz del índice 1 al 3
	cout<<"La suma de valores en el rango del índice 1 al 3  en el arreglo es = "<<getSum(stree, n, 1, 3)<<endl; 

	// Actualización: establecer arr [1] = 10 y actualizar correspondiente
	// segmentar nodos de árbol 
	updateValue(arr, stree, n, 1, 10); 

	// Encuentra la suma después de actualizar el valor 
	cout<<"La suma después de actualizar = "<<getSum(stree, n, 1, 3)<<endl; 

	int qini = 1; // indicee del inicio
	int qfin = 5; // indice del final

	//imprime el minimo valor dntro del rango
	cout<<"el minimo valor dntro del rango ["<<qini<<", "<<qfin<<"] "<< "es = "<<RMQ(stree, n, qini, qfin)<<endl; 
	return 0; 
} 
/* La complejidad del tiempo para la construcción de árboles es O (n).
Hay un total de 2n-1 nodos, y el valor de cada nodo
se calcula solo una vez en la construcción del árbol.

La complejidad de tiempo para consultar es O (Logn). Para consultar una suma,
 procesamos como máximo cuatro nodos en cada nivel y número
 de niveles es O (Logn).

La complejidad temporal de la actualización también es O (Logn).
 Para actualizar un valor de hoja, procesamos un nodo en
 cada nivel y número de niveles es O (Logn).
*/
