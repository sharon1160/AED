#include<iostream>
#include <stack>

using namespace std;

string convInfija()
{
    stack<string> pila;
    string cad;
    string a, b;
    cout<<"cadena ?"<<endl;
    cin>>cad;
    while (cad[0] != '=')
    {
        if (cad[0] >= 'a' && cad[0] <= 'z')
            pila.push(cad);
        else{
            switch (cad[0])
            {
                case '+' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top(); 
                    pila.pop();
                    pila.push("("+ a+" + " + b+")"); 
                    break;
                case '-' :
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top(); 
                    pila.pop();
                    pila.push("("+a+" - "+ b+")"); 
                    break;
                case '*' :
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top(); 
                    pila.pop();
                    pila.push("("+a+" * "+ b+")"); 
                    break;
                case '/' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top(); 
                    pila.pop();
                    pila.push("("+a+" / " + b+")"); 
                    break;
                case '^' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b =pila.top(); 
                    pila.pop();
                    pila.push("("+a+" ^ " + b+")"); 
                    break;
            }
        }
        cout<<"cadena ?"<<endl;
        cin>> cad;
    }
    return pila.top();
}

int main()
{
   //posfija ----> a b c * +
   //infija ----> ((c*b)+a)
   cout<<"Expresion postfija convertida a Infija : "<<convInfija()<<endl;
   return 0;
}
