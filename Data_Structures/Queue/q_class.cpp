#include<iostream>
#include "q.h"
using namespace std;

int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(5);
    cout<< q.dequeue();
    cout<< q.dequeue();
    cout<< q.dequeue();
    cout<< q.dequeue();
    cout<< q.dequeue();
    cout<< q.dequeue();
    cout<< q.dequeue();
    return 0;
}