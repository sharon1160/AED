#include <iostream>

using namespace std;

#define SIZE 5

int A[SIZE];
int front = -1;
int post = -1;

//Function to check if queue is empty or not
bool isempty()
{
     if(front == -1 && post == -1)
        return true;
     else
        return false;
}

//function to enter elements in queue
void insertar( int valor )
{
     //queue is full
     if ((post + 1)%SIZE == front)
        cout<<endl<<"La cola esta llena "<<endl;
     else
     {
      //first element inserted
      if( front == -1)
         front = 0;
     //insert element at rear
     post = (post+1)%SIZE;
     A[post] = valor;
    }
}

//function to delete/remove element from queue
void quitar( )
{
     if( isempty() )
        cout<<endl<<"La cola esta vacia"<<endl;
     else{
         //only one element
         if( front == post )
          front = post = -1;
         else
          front = (front + 1)%SIZE;
     }
}

//function to show the element at front
void elementoCabeza( )
{
     if( isempty())
        cout<<endl<<"La cola esta vacia"<<endl;
     else
        cout<<endl<<"Elemento cabeza es:"<<A[front]<<endl;
}

//function to display queue
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
