#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* next;
}node;

int main()
{   
    node* ptr = nullptr;
    ptr = new node;
    ptr->val = 1;
    ptr->next = nullptr;
    return 0;
}