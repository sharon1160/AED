#include <iostream>
#include "RB.h"
using namespace std;

int main() {
	
    RBTree<int> tree;
    cout<<"VALOR     COLOR (0:NEGRO Y 1:ROJO)"<<endl;
    tree.insert(7); 
    tree.insert(3); 
    tree.insert(18); 
    tree.insert(10); 
    tree.insert(22); 
    tree.insert(8); 
    tree.insert(11); 
    tree.insert(26); 
    tree.insert(2); 
    tree.insert(6); 
    tree.insert(13); 
    tree.mostrar();
    cout<<"Eliminando : 18,11,3,10,22"<<endl;
    tree.remove(18);
    tree.remove(11);
    tree.remove(3);
    tree.remove(10);
    tree.remove(22);
    tree.mostrar();
    
    
    
    return 0;
}
