#include<iostream>
using namespace std;

#define DEFAULT_CAPACITY  16

template<class T>
class Vector{
     private:
    	int sizee;
		int capacidad;
		T * head;
		T * tail;
	public:
		typedef T* iterator;
		Vector(int tamInicial = 0)  /////// constructor
		:sizee(tamInicial), capacidad(tamInicial+DEFAULT_CAPACITY)
		{
			head = new T[capacidad];
			tail = head + tamInicial;
		}
		
		~Vector(){  // destructor
			delete [] head;
		}
		
		T & operator[](int indicador){ // sobrecarga de operador
			if(indicador>=0 && indicador<size()){
				return head[indicador];
			}
			else{
				cout<<"Indice fuera de los limites";
				return head[0];
			}
		}
		
		void push_back(const T & obj){ 
			if(sizee == capacidad){
				resize(capacidad *= 2);
			}
			head[sizee++] = obj;
			++tail;
		}
		
		void pop_back(){ 
			--sizee;
		}	
		
		void resize(int new_capacidad){  
			T * original = head;
			if(new_capacidad>=capacidad){
				head = new T[new_capacidad];
			}
			tail = head + sizee;		
			for(int i=0; i<sizee; ++i){
				head[i] = original[i];
			}
			delete [] original;
		}
		
		int size() const{
			return sizee;
		}
		
		int capacity() const{
			return capacidad;
		}
		
		iterator begin(){
			return head;
		}
		
		iterator end(){
			return tail;
		}
		
		iterator insert(const T & obj, iterator itr){
			if(sizee == capacidad)
			    resize(capacidad *= 2);
			for(iterator mod_itr = end(); mod_itr != itr; --mod_itr)
			    *mod_itr = *(mod_itr-1);
		    *itr = obj;
		    ++sizee;
		    ++tail;
		    return itr+1;
		}
		
		iterator erase(iterator itr){ // funcion erase
			for(iterator mod_itr = itr; mod_itr+1 != end(); ++mod_itr)
			    *mod_itr = *(mod_itr+1);
		    --sizee;
		    --tail;
			return itr;
		}
};

int main(){
	Vector<int> vector;
	vector.push_back(1);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	for(int i=-2;i<9;i++){
		cout<<vector[i]<<endl;
	}
}
