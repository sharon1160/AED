#include <cassert>
#include <iostream>

using namespace std;

template <typename T> 
class DosPilas {
    public:
      DosPilas(int n); 
      ~DosPilas();
      void push1(T x);//insertar elemento a la primera pila
      void push2(T x);//insertar elemento a la segunda pila
      T pop1();
      T pop2();
    
    private:
      T *arr;
      int size;
      int top1, top2;
};

template <typename T> 
DosPilas<T>::DosPilas(int n) {
  size = n;
  arr = new T[n];
  top1 = -1;
  top2 = n;
}

template <typename T> 
DosPilas<T>::~DosPilas() { 
    delete[] arr; 
}

template <typename T> 
void DosPilas<T>::push1(T x) {
  assert(top1 + 1 != top2);
  top1++;
  arr[top1] = x;
}

template <typename T> 
void DosPilas<T>::push2(T x) {
  assert(top2 - 1 != top1);
  top2--;
  arr[top2] = x;
}

template <typename T> 
T DosPilas<T>::pop1() {
  assert(top1 != 0);
  T x = arr[top1];
  top1--;
  return x;
}

template <typename T> 
T DosPilas<T>::pop2() {
  assert(top2 != size);
  T x = arr[top2];
  top2++;
  return x;
}

int main() {
  DosPilas<int> ds(5);
  ds.push1(1);
  ds.push1(2);
  ds.push1(0);
  ds.push1(4);
  ds.push2(7);
  std::cout << ds.pop1() << '\n';//la funcion pop1
  std::cout << ds.pop2() << '\n';// y pop2 retorna 
  std::cout << ds.pop1() << '\n';//el elemento a eliminar
  std::cout << ds.pop1() << '\n';

  return 0;
}
