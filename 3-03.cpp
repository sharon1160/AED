#include<iostream>
#include <list>

using namespace std;


template<class iterator,class T>
iterator find( iterator start, iterator end, T &x ){
    iterator itL;
    itL=start;
    while(itL!=end && *itL!=x)
        itL++;
    return itL;
    
}

int main(){
	list<int> L;
	L={1,2,3,4,5,6,7,8,9};
	list<int>::iterator itinicio; 
	list<int>::iterator itfinal; 
	itinicio=L.begin();
	itfinal=L.end();
	int num=7;
	cout<<*(find(itinicio,itfinal,num));
	return 0;
}
