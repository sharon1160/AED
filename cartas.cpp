#include <iostream>
using namespace std;

template<class T>
class Node
{
	private:
    	T dato;
		Node<T>* siguiente;
	public:
		Node(T);
		void setSiguiente(Node<T>*);
		void setDato(T);
		Node<T>* getSiguiente();
		T getDato();
};
//constructor
template<class T>
Node<T>::Node(T _dato)
{
    siguiente=NULL;
    dato = _dato;
}
//Establece el puntero al nodo siguiente
template<class T>
void Node<T>::setSiguiente(Node<T>* _siguiente)
{
    siguiente = _siguiente;
}

template<class T>
void Node<T>::setDato(T _dato)
{
    dato = _dato;
}
//se obtiene el puntero al siguiente
template<class T>
Node<T>* Node<T>::getSiguiente()
{
    return siguiente;
}
//se obtiene el contenido del nodo
template<class T>
T Node<T>::getDato()
{
    return dato;
}


template<class T>
class LinkedList
{
    private:
        Node<T> *head;
        int tam;
    public:
        LinkedList();//constructor
        ~LinkedList();//destructor

        void push_front(T);//para poner un elemento delante de toda la lista
        void push_back(T);//para poner un elemto al final de la lista
        void add(T,int);//para añadir un elemento de tipo T en alguna posicion

        T get_front();//para obtener el primer elemento
        T get_back();//para obtener el ultimo elemento
        T get(int);//para obtener un dato de la posicion en la que se desea

        void eliminar_front();//para eliminar el primer elemento
        void eliminar_back();//para eliminar el ultimo elemento
        void eliminar(int);//para eliminar cualquier elemento

        void cartas(int);
        int getSize()//para obtener el tamanio
        {
            return tam;
        }

        void mostrar();//para mostrar la lista
};


template<class T>
LinkedList<T>::LinkedList()
{
    head=NULL;
    tam=0;
}

template<class T>
void LinkedList<T>::push_back(T dato)
{
    Node<T>* aux =  new Node<T>(dato);

    if(head==NULL)
        head = aux;

    else
    {
        Node<T>* ptr = head;
        while(ptr->getSiguiente() != NULL)
            ptr = ptr->getSiguiente();
        ptr->setSiguiente(aux);
    }
    tam++;
}

template<class T>
void LinkedList<T>::push_front(T dato)
{
    Node<T> *aux =  new Node<T>(dato);
    aux->setSiguiente(head);
    head = aux;
    tam++;
}

template<class T>
void LinkedList<T>::add(T dato,int n)
{
    Node<T>* aux =  new Node<T>(dato);

    if(n>tam)
        cout<<"introduzca un numero menor al tamaño de la lista";
    else if(n==0)
    {
        aux->setSiguiente(head);
        head = aux;
    }
    if(head==NULL)
        head = aux;
    else
    {
        int cont = 0;
        Node<T>* puntero = head ;
        while(cont < (n-1))
        {
            puntero = head->getSiguiente();
            cont++;
        }
        aux->setSiguiente(puntero->getSiguiente());
        puntero->setSiguiente(aux);
    }
    tam++;
}

template<class T>
T LinkedList<T>::get_front()
{
    if(tam == 0)
       return NULL;
    return (head->getDato());
}

template<class T>
T LinkedList<T>::get_back()
{
    if(tam == 0)
        return NULL;
    Node<T>* ptr = head;
    while(ptr->getSiguiente()  != NULL)
        ptr = ptr->getSiguiente();
    return (ptr->getDato());

}

template<class T>
T LinkedList<T>::get(int n)
{
    if(n>=tam)
       return NULL;
    Node<T> ptr = head;
    int cont = 0;
    while(cont < n)
        ptr = ptr->getSiguiente();
    return (ptr->getDato());
}

template<class T>
void LinkedList<T>::eliminar_front()
{
    if(tam ==0) return ;
    Node<T>* elimnado = head;
    head = head->getSiguiente();
    delete elimnado;
    tam--;
}


template<class T>
void LinkedList<T>::eliminar_back()
{
    if(tam ==0)
       return ;
    if(tam ==1)
        eliminar_front();
    else
    {
        Node<T>* ptr = head;
        while(ptr->getSiguiente()->getSiguiente() != NULL)
            ptr = ptr->getSiguiente();
        Node<T>* eliminado = ptr->getSiguiente();
        ptr->setSiguiente(NULL);
        delete eliminado;
        tam--;
    }
}

template <class T>
void LinkedList<T>::eliminar(int n)
{
    if(n >= tam)
        return ;
    if(n == 0)
        eliminar_front();
    else
    {
        Node<T>* ptr = head;
        int cont = 0;
        while(cont < (n-1) )
        {
            ptr = ptr->getSiguiente();
            cont++;
        }
        Node<T>* eliminado = ptr->getSiguiente();
        ptr->setSiguiente(eliminado->getSiguiente());
        delete eliminado;
        tam--;
    }
}

template<class T>
void LinkedList<T>::cartas(int tam)
{
    int front;
    int count=1;
    while(count!=(tam*2)-2){
        if(count%2!=0){
            cout<<get_front()<<" ";
            eliminar_front();
        }
        else if(count%2==0){
                front=get_front();
                eliminar_front();
                push_back(front);
                
        }
        count++;
        
    }
    cout<<endl;
    cout<<"Numero final :"<<endl;
    mostrar();
}

template<class T>
void LinkedList<T>::mostrar()
{
    Node<T>* ptr = head;
    for(int i =0 ; i<tam ; i++)
    {
        cout << ptr->getDato() <<" ";
        ptr = ptr->getSiguiente();
    }
    cout <<endl;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    for(int i =0 ; i<tam ; i++)
    {
        Node<T>* lista = head;
        head = head->getSiguiente();
        delete lista;
    }
}

int main()
{
    int n;
    LinkedList<int> listanumeros;
    cout<<"Cuantos numeros ?"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
        listanumeros.push_back(i+1);
    cout<<listanumeros.get_front()<<endl;
    cout<<listanumeros.get_back()<<endl;
    cout<<"Lista"<<endl;
    listanumeros.mostrar();
    cout<<"____________"<<endl;
    cout<<"Numeros descartados: "<<endl;
    listanumeros.cartas(n);
    return 0;
}
