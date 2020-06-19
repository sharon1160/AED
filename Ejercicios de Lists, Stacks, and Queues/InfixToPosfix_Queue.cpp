#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Para ver si el caractér es un número o no
bool isNumber(char c) {
  c = c - '0';
  return (c >= 0 && c <= 9);
}

// Devuelve el resultado de la expresión dada
int evaluate(queue<char> &expr) {
  stack<int> s;
  while (!expr.empty()) {
    char c = expr.front();
    while (isNumber(c)) {
      s.push(c - '0'); // Conversion a entero
      expr.pop();
      c = expr.front();
    }
    // Evaluando
    expr.pop(); // Quitando operador
    int op1 = s.top();
    s.pop();
    int op2 = s.top();
    s.pop();
    switch (c) {
    case '+':
      s.push(op1 + op2);
      break;
    case '*':
      s.push(op1 * op2);
      break;
    default:
      throw runtime_error("Operador inválido.");
    }
  }
  return s.top();
}

/*
 * Retorna la precedencia de un operador.
 * (^) = 3
 * (* y /) = 2
 * (+ y -) = 1
 */
int precedencia(char c) {
  switch (c) {
  case '^':
    return 3;
  case '*':
  case '/':
    return 2;
  case '+':
  case '-':
    return 1;
  default:
    return -1;
  }
}

// Función para convertir de infijo a postfijo
void infixToPostfix(queue<char> &out, queue<char> &in) {

  stack<char> s;
  s.push('N');
  while (!in.empty()) {
    char c = in.front();
    in.pop();
    if (isNumber(c)) {
      out.push(c);
    }
    else if (c == '(') {
      s.push(c);
    }
    else if (c == ')') {
      char op = s.top();
      while (op != '(') {
        out.push(op);
        s.pop();
        op = s.top();
      }
      s.pop();
    }
    else {
      char op = s.top();
      while (precedencia(op) >= precedencia(c)) {
        out.push(op);
        s.pop();
        op = s.top();
      }
      s.push(c);
    }
  }
  char op = s.top();
  while (op != 'N') {
    out.push(op);
    s.pop();
    op = s.top();
  }
}

int main() {
  queue<char> in;
  char c = ' ';
  std::cin >> c
  while (c!=-1) {
    in.push(c);
  }
  queue<char> out;
  infixToPostfix(out, in);
  std::cout << evaluate(out) << '\n';
  return 0;
}
