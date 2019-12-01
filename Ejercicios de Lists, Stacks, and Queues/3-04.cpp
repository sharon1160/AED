#include<iostream>
#include <list>

using namespace std;

template <class T>
list<T> interseccion( list<T> L1,list<T> L2)
{
    list<T> L_interseccion;
    class list<T>:: iterator itL1;
    class list<T>:: iterator itL2;
    
    itL1 = L1.begin();
    itL2= L2.begin();
    
    
    while(itL1!=L1.end() && itL2!=L2.end())
    {
        if (*itL1 == *itL2)
        {
            L_interseccion.push_back(*itL1);
            itL1++;
            itL2++;
        }
        else if (*itL1 < *itL2)
                itL1++;
        else
                itL2++;
    }
    return L_interseccion;
}

int main(){
	list<int> L1;
	L1={1,2,3,4,5,6,7,8,9};
	list<int> L2;
	L2={1,2,3,10};
	
	list<int>::iterator itL3;
	list<int> L3;
	L3=interseccion(L1,L2);
	for(itL3=L3.begin();itL3!=L3.end();itL3++)
	    cout<<*itL3<<" ";
	return 0;
}
