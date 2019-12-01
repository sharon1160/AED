#include<iostream>
#include <stack>

using namespace std;

void aPostfija()
{
    stack<char> p;
    char token;
    cin>> token;
    while (token != '=')
    {
        if (token >= 'a'&& token <= 'z')
            cout<<token<<" ";
        else{
            switch (token)
            {
                case ')' : 
                    while(!p.empty() && p.top() != '(')
                    { 
                        cout<<p.top()<<" "; 
                        p.pop();
                    }
                    p.pop();
                    break;
                case '(' : 
                    p.push(token); 
                    break;
                case '^' : 
                    while(!p.empty() && !(p.top()== '^' || p.top() == '('))
                    {
                        cout<<p.top()<<" "; 
                        p.pop();
                    }
                    p.push(token); 
                    break;
                case '*' :
                case '/' : 
                    while(!p.empty() && p.top() != '+' && p.top() != '-' && p.top() != '(')
                    {
                        cout<<p.top()<<" "; 
                        p.pop();
                    }
                    p.push(token); 
                    break;
                case '+' :
                case '-' : 
                    while(!p.empty() && p.top() != '(' )
                    {
                        cout<<p.top()<<" "; 
                        p.pop();
                    }
                    p.push(token); 
                    break;
            }
        }
        cin>> token;
    }
    while (!p.empty()){
        cout<<p.top()<<" "; 
        p.pop();
    }
    cout<<" = \n";
}
int main()
{
   aPostfija();
   return 0;
}
