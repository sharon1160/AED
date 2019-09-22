#include<iostream>

//Ejercicio 3.27 :
//Si la rutina recursiva en la Sección 2.4 utilizada 
//para calcular los números de Fibonacci
//se ejecuta para N = 50, ¿es probable que se agote el 
//espacio de la pila? ¿Por qué o por qué no?

//Respuesta: Cuando N sea igual a 50 es probable que 
//se agote el espacio de pila ,ya que al llamar la funcion de Fibonacci 
//retornara un numero grande llegando ha sobrepasar el rango de long,
//que es el tipo de dato que tiene de retorno la funcion fib, long solo llega
//hasta el numero 2147483647 con 32 bits;
//con n=50 el resultado sobrepasaría el limite de long
//ocasionando la agotacion del espacio de la pila


using namespace std;

long fib( int n )
{
    if( n <= 1 )
        return 1;
    else
        return fib( n - 1 ) + fib( n - 2 );
}

int main(){
    int n;
    cout<<"numero?"<<endl;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
