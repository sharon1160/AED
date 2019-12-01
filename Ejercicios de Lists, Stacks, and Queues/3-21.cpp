#include <cassert>
#include <iostream>
#include <stack>

void match(std::stack<char> &p, const char symbol) {
  assert(!p.empty());
  char opening = p.top();
  p.pop();
  assert(opening == symbol);
}

int main() {
  std::stack<char> p;
  char c = ' ';
  while (std::cin >> c) {
    switch (c) {
    case '(':
    case '[':
    case '{': {
      p.push(c);
      continue;
    }
    case ')': {
      match(p, '(');
      continue;
    }
    case ']':
      match(p, '[');
      continue;
    case '}':
      match(p, '{');
      continue;
    default:
      continue;
    }
  }
  assert(p.empty());
  return 0;
}
