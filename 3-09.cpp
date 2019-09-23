#include <iostream>
#include <vector>

using namespace std;


int main(){
	vector<int> v;
	v={1,2,3,4,5,6,7,8,9};
	vector<int>::iterator itinicio; 
	vector<int>::iterator itfinal; 
	itinicio=v.begin();
	itfinal=v.end();
	cout<<"___________ANTES DE LAS OPERACIONES____________"<<endl;
	cout<<"El primer elemento con iterador : "<<*itinicio<<endl;//muestra el 
	                                                           //primer elemento
	cout<<"El ultimo elemento con iterador : "<<*itfinal<<endl;
	cout<<"Realizando las operaciones ..."<<endl;
	v.push_back(10);
	v.push_back(11);
	v.pop_back();
	cout<<"__________DESPUES DE LAS OPERACIONES____________"<<endl;
	cout<<"El primer elemento con iterador : "<<*itinicio<<endl;//el iterador se hace invalido
	cout<<"El ultimo elemento con iterador : "<<*itfinal<<endl;
	cout<<"___________MOSTRANDO LA LISTA____________"<<endl;
	vector<int>::iterator mostrar; 
	for(mostrar=v.begin();mostrar!=v.end();++mostrar)
	    cout<<*mostrar<<" ";
	return 0;
}
