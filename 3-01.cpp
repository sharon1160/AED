#include <iostream>
#include <list>
#include<ctime>

using namespace std;


void printLots(list <int> L,list <int> P)
{
    list<int>::iterator itL;
    list<int>::iterator itP;
	int cont;
    for(itP = P.begin(); itP != P.end(); ++itP){
        cont=0;
    	for(itL = L.begin(); itL != L.end(); ++itL) {
    		if(*itP==cont){
    			cout<<*itL<<endl;
			}
			cont++;
		}
	}
}

int main(){
    float tiempo1,tiempo2;
	list<int> L={1,2,3,4,5,6,7,8,9};
	list<int> P={1,3,4,6};
	tiempo1 =clock();
	printLots(L,P);
	tiempo2=clock();
	float tiempo = (float(tiempo2-tiempo1)/CLOCKS_PER_SEC);//tiempo en segundos
	cout<<"Tiempo de ejecucion:"<<tiempo;
	return 0;
}
