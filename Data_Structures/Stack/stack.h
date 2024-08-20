#ifndef __stack_h__
#define __stack_h__

#include<vector>
using namespace std;

template <typename T>
class Stack
{
    private:
    vector<T> v;
    int top;

    public:
    Stack():top{-1}{}
    T peek(){return v[top];}
    void push(T item)
    {
        v.push_back(item);
        top++;
    }
    T pop()
    {
        if(empty())
        {
            cout<<"Stack is empty!\n";
            return '\0';
        }

        T temp = v[top];
        v.erase(v.begin()+top);
        top--;
        return temp;
    }
    bool empty()
    {
        if(v.begin() == v.end())
            return true;
        else return false;
    }
};

#endif