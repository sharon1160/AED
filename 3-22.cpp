#include <iostream>
#include <stack>
#include <cmath>
#include <cstdlib> 
#include <string>

using namespace std;

double evalPosFija( )
{
    stack<double> pila;
    string cad;
    double a, b, result;
    cout<<endl;
    cout<<"cadena ?"<<endl;
    cin>> cad;
    while (cad[0] != '=')
    {
        result = atof(cad.c_str());
        if (result != 0.0 ){
            pila.push(result);
        }
        else if (cad == "0.0"){
            pila.push(result);
        }
        else{
             switch (cad[0])
            {
                case '+' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(a+b); 
                    break;
                case '-' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(a-b); 
                    break;
                case '*' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(a*b); 
                    break;
                case '/' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(b/a); 
                    break;
                case '^' : 
                    a = pila.top(); 
                    pila.pop(); 
                    b = pila.top();
                    pila.pop(); 
                    pila.push(exp(a*log(b)));
                    break;
            }
        }
        cout<<"cadena?"<<endl;
        cin>> cad;
    }
    return pila.top();
}


int main()
{
    cout<<"Hello World";
    //si la expresion no es Posfija mostrara
    //Segmentation fault
    cout<<"Resulado final : "<<evalPosFija()<<endl;
    return 0;
}

