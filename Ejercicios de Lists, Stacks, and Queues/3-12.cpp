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

        void push_back(T);//para poner un elemto al final de la lista

        T get_front();//para obtener el primer elemento
        T get_back();//para obtener el ultimo elemento
        T get(int);//para obtener un dato de la posicion en la que se desea

        void eliminar_front();//para eliminar el primer elemento
        void eliminar_back();//para eliminar el ultimo elemento
        void eliminar(int);//para eliminar cualquier elemento
        void insert(T);
        bool buscar(T);
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

template <class T>
void LinkedList<T>::insert(T dato)
{
    bool alerta=false;
    Node<T>* ptro=head;
    for(int i=0;i<tam;i++){
        if(ptro->getDato()==dato){
            alerta=true;
            break;
        }
        else{
            ptro=ptro->getSiguiente();
        }
    }
    if(alerta==false){
        Node<T> *current; 
        Node<T> *trailCurrent; 
        Node<T> *newNode; 
        bool found;
        newNode = new Node<T>(dato);
        newNode->setDato(dato); 
        newNode->setSiguiente(NULL); 
        if (head == NULL) 
        {
            head = newNode;
            tam++;
        }
        else
        {
            current = head;
            found = false;
            while (current != NULL && !found) 
                if (current->getDato() >= dato)
                    found = true;
                else
                {
                    trailCurrent = current;
                    current = current->getSiguiente();
                }
                if (current == head) 
                {
                    newNode->setSiguiente(head);
                    head = newNode;
                    tam++;
                }
    
                else
                {
                    trailCurrent->setSiguiente(newNode);
                    newNode->setSiguiente(current);
                    tam++;
                }
        }
    }
    else{
        cout<<"Existe el elemento"<<endl;
    }
}

template<class T>
void LinkedList<T>::push_back(T dato)
{
 
    bool alerta;
    Node<T>* comprobador=head;
    for(int i=0;i<tam;i++){
        if (comprobador->getDato()==dato){
            alerta=true;
            break;
        }
        else{
            alerta=false;
            comprobador=comprobador->getSiguiente();
        }
    }
    if(alerta==false){
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
    else{
        cout<<"Ingrese otro numero"<<endl;
    }
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
bool LinkedList<T>::buscar(T dato){
    bool alerta=false;
    Node<T>* ptro=head;
    for(int i=0;i<tam;i++)
    {
        if(ptro->getDato()==dato){
            alerta=true;
            break;
        }
        else
            ptro=ptro->getSiguiente();
    }
    return alerta;
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
    LinkedList<int> listanumeros;
    listanumeros.insert(0);
    listanumeros.insert(5);
    listanumeros.insert(7);
    listanumeros.insert(6);
    listanumeros.insert(1);
    listanumeros.insert(2);
    listanumeros.insert(4);
    listanumeros.insert(3);
    listanumeros.insert(3);
    cout<<"Tamanio de la lista es: "<<listanumeros.getSize()<<endl;
    cout<<"LISTA :";
    listanumeros.mostrar();
    if(listanumeros.buscar(5)==true)
        cout<<"El elemento buscado si esta"<<endl;
    else
        cout<<"El elemento buscado no esta"<<endl;
    listanumeros.eliminar_back();
    cout<<"LISTA :";
    listanumeros.mostrar();
    return 0;
}
