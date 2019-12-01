#include<iostream>
#include <list>

using namespace std;


template <class T>
list<T> funcion_union( list<T> L1,list<T> L2)
{
    class list<T> L_union;
    
    class list<T>::  iterator itL1;
    class list<T>::  iterator itL2;
    
    itL1 = L1.begin();
    itL2= L2.begin();
    
    while(itL1!=L1.end() && itL2 != L2.end())
    {
        if (*itL1 == *itL2){
            
            L_union.push_back(*itL1);
            itL1++;
            itL2++;
        }
        else if (*itL1 < *itL2){
            
            L_union.push_back(*itL1);
            itL1++;
            if(itL1==L1.end())
                itL1=itL2;
        }
        else{
            
            L_union.push_back(*itL2);
            itL2++;
            if(itL2==L2.end())
                itL2=itL1;
        }
    }
    return L_union;
}

int main(){
	list<int> L1;
	L1={1,2,5,7};
	list<int> L2;
	L2={2,4};
	
	list<int>::iterator itL3;
	list<int> L3;
	L3=funcion_union(L1,L2);
	for(itL3=L3.begin();itL3!=L3.end();itL3++)
	    cout<<*itL3<<" ";
	return 0;
}
