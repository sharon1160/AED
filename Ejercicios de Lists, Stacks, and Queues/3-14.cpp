#include <iostream>

using namespace std;

template< class T> 
class Nodo{
    private:
        T dato;
        Nodo* anterior;
        Nodo* siguiente;
        
    public:
        Nodo(T _dato){
            siguiente=NULL;
            anterior=NULL;
            dato=_dato;
        }
        void setSiguiente(Nodo<T>* _siguiente){
            siguiente= _siguiente;
        }
        void setAnterior(Nodo<T>* _anterior){
            anterior=_anterior;
        }
        void setDato(T _dato){
            dato=_dato;
        }
        Nodo<T>* getSiguiente(){
            return siguiente;
        }
        Nodo<T>* getAnterior(){
            return anterior;
        }
        T getDato()
        {
            return dato;
        }

};

template <class T>
class ListaDoble
{
    private:
        Nodo<T>* head;
        Nodo<T>* cola;
        int tam;
    public:
        ListaDoble(){//constructor
            head=NULL;
            cola=NULL;
            tam=0;
        }
        ~ListaDoble(){//destructor
            for(int i =0 ; i<tam ; i++)
            {
                Nodo<T>* lista = head;
                head = head->getSiguiente();
                delete lista;
            }
        }
        void mostrar(){//para mostrar la lista
            Nodo<T>* aux=head;
            while(aux!=NULL){
                cout<<aux->getDato()<<" ";
                aux=aux->getSiguiente();
            }
            cout<<endl;
        }
        void push(T dato){//para añadir a la parte frontal de la lista
            Nodo<T> *aux =  new Nodo<T>(dato);
            if(tam==0){
                aux->setAnterior(NULL);
                aux->setSiguiente(head);
                cola=aux;
                head = aux;
                tam++;
            }
            else if(tam>0){
                aux->setAnterior(NULL);
                aux->setSiguiente(head);
                head->setAnterior(aux);
                head = aux;
                tam++;
            }
        }
        
        void inyectar(T dato){//para añadir al final de la lista
            Nodo<T> *aux =  new Nodo<T>(dato);
            if(tam==0){
                push(aux->getDato());
            }
            else if(tam>0){
                aux->setAnterior(cola);
                aux->setSiguiente(NULL);
                cola->setSiguiente(aux);
                cola=aux;
                tam++;
            }
        }
        
        T pop(){//para eliminar el elemento frontal de la lista
                T dato;
                if(tam==0){
                       return 0;
                }
                else if(tam>0){
                        Nodo<T> *eliminar = head;
                        head=head->getSiguiente();
                         dato=eliminar->getDato();
                         delete eliminar;
                        tam--;
                        return dato;
               }
        }
        T expulsar(){//para eliminar el ultimo elemento de la lista
            T dato;
            if(tam==0){
                return 0;
            }
            else if(tam>0){
                Nodo<T> *eliminar = cola;
                cola=cola->getAnterior();
                cola->setSiguiente(NULL);
                dato=eliminar->getDato();
                delete eliminar;
                tam--;
                return dato;
                
            }
        }
        Nodo<T>* begin()
        {
            return head;
        }
        Nodo<T>* end()
        {
            return cola;
        }
};

template <class T>
class Iterator
{
    public:
        virtual bool hasNext()=0;
        virtual Nodo<T>* next()=0;
        virtual bool hasAnt()=0;
        virtual Nodo<T>* ant()=0;
};

template <class T>
class IteratorList : public Iterator<T>
{
    private:
        Nodo<T>* iterador;
    public:
        IteratorList();//constructor por defecto
        IteratorList(Nodo<T>* ite){//constructor con argumento
            iterador=ite;
        }
        virtual bool hasAnt();
        virtual Nodo<T>* ant();
        virtual bool hasNext();
        virtual Nodo<T>* next();
        
        IteratorList<T> operator+(int k) const{
            Nodo<T>* iterador1=iterador;
            for(int i=0;i<k;i++)
                iterador1 = iterador1->getSiguiente();
            IteratorList<T> itlist(iterador1);
            return itlist;
        }

        Nodo<T>* operator++();
        Nodo<T>* operator--();
        void operator=(Nodo<T>* ptro);
        bool operator!=(Nodo<T>* ptro);
        T operator*();

};

template<class T>
IteratorList<T>::IteratorList()
{
    iterador=NULL;
}

template<class T>
bool IteratorList<T>::hasNext()
{
    return (iterador !=NULL);
}

template<class T>
Nodo<T>* IteratorList<T>::next()
{
    iterador = iterador->getSiguiente();
    return iterador;
}
template<class T>
bool IteratorList<T>::hasAnt()
{
    return (iterador !=NULL);
}

template<class T>
Nodo<T>* IteratorList<T>::ant()
{
    iterador = iterador->getAnterior();
    return iterador;
}
template<class T>
Nodo<T>* IteratorList<T>::operator++()
{
    return next();
}

template<class T>
Nodo<T>* IteratorList<T>::operator--()
{
    return ant();
}

template<class T>
void IteratorList<T>::operator=(Nodo<T>* ptro)
{
    iterador = ptro;
}

template<class T>
bool IteratorList<T>::operator!=(Nodo<T> *ptro)
{
    return iterador!=ptro;
}

template<class T>
T IteratorList<T>::operator*()
{
    return iterador->getDato();
}


int main()
{
    ListaDoble<int> lis;
    lis.push(3);
    lis.push(6);
    lis.push(8);
    lis.push(12);
    lis.push(4);
    lis.inyectar(5);
    lis.inyectar(2);
    cout<<"_____________Lista___________"<<endl;
    lis.mostrar();
    cout<<"Primer dato ha eliminar : "<<lis.pop()<<endl;
    cout<<"_____________Lista___________"<<endl;
    lis.mostrar();
    cout<<"Utimo dato ha eliminar : "<<lis.expulsar()<<endl;
    cout<<"_____________Lista___________"<<endl;
    lis.mostrar();
    cout<<"Utimo dato ha eliminar : "<<lis.expulsar()<<endl;
    cout<<"_____________Lista___________"<<endl;
    lis.mostrar();
    IteratorList<int> it;
    it=lis.begin();
    cout<<*it<<endl;// 12
    cout<<"IteradorLista "<<2<<" posiciones adelante es : "<<*(it+2)<<endl;//6
    cout<<*it<<endl;// 12
    return 0;
}
