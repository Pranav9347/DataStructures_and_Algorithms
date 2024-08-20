#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* next;
}node;

void view_list(node*);
node* insert_at_beginning(node*, int);


int main()
{   
    node* head = nullptr;
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 2);
    view_list(head);
    return 0;
}


void view_list(node* temp)
{
    while(temp != nullptr)
    {
        cout << temp->val;
        temp = temp->next;
    }
    return;
}

node* insert_at_beginning(node* head, int item)
{
    node* temp = new node;
    temp->val = item;
    temp->next = head;
    return temp;
}