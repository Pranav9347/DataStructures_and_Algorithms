#include<iostream>
#include "stack.h"
using namespace std;



int main()
{
    Stack<char> s;
    s.push('a');
        cout<<s.peek();
    s.push('b');
    cout << s.pop();
    cout<<s.pop();
    cout<<s.pop();
    return 0;
}