#include <iostream>

using namespace std;

#define SIZE 5

int A[SIZE];
int front = -1;
int post = -1;

//Funcion para verificar si la cola esta vacia
bool isempty()
{
     if(front == -1 && post == -1)
        return true;
     else
        return false;
}

//funcion para insertar elementos a la cola
void insertar( int valor )
{
     if ((post + 1)%SIZE == front)
        cout<<endl<<"La cola esta llena "<<endl;
     else
     {
      if( front == -1)
         front = 0;
     post = (post+1)%SIZE;
     A[post] = valor;
    }
}

//funcion para eliminar un elemento de la cola
void quitar( )
{
     if( isempty() )
        cout<<endl<<"La cola esta vacia"<<endl;
     else{
         if( front == post )
          front = post = -1;
         else
          front = (front + 1)%SIZE;
     }
}

//funcion para mostrar un elemento de adelante
void elementoCabeza( )
{
     if( isempty())
        cout<<endl<<"La cola esta vacia"<<endl;
     else
        cout<<endl<<"Elemento cabeza es:"<<A[front]<<endl;
}

//funcion para mostrar la cola
void mostrar()
{
     if(isempty())
        cout<<endl<<"La cola esta vacia"<<endl;
     else
     {
          int i;
          if( front <= post )
          {
               for( i=front ; i<= post ; i++)
                    cout<<A[i]<<" ";
          }
          else
          {
               i=front;
               while( i < SIZE)
               {
                   cout<<A[i]<<" ";
                   i++;
               }
               i=0;
               while( i <= post)
               {
                   cout<<A[i]<<" ";
                   i++;
                }
           }
    }
}

int main()
{
 int eleccion, flag=1, valor;
 while( flag == 1)
 {
  cout<<endl<<"1.Insertar 2.Quitar 3.ElementoCabeza 4.Mostrar 5.exit"<<endl;
  cin>>eleccion;
  switch (eleccion)
  {
      case 1: cout<<"Ingrese numero :"<<endl;
              cin>>valor;
              insertar(valor);
              break;
      case 2: quitar();
              break;
      case 3: elementoCabeza();
              break;
      case 4: mostrar();
              break;
      case 5: flag = 0;
              break;
      }
 }

 return 0;
}
