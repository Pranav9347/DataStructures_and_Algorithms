#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* next;
}node;

void view_list(node*);
node* insert_at_end(node*, int);


int main()
{   
    node* head = nullptr;
    head = insert_at_end(head, 2);
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

node* insert_at_end(node* temp, int item)
{
    node* head = temp;
    if(temp == nullptr)
    {
        temp = new node;
        temp->val = item;
        temp->next = nullptr;
        return temp;
    }
    else
    {
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new node;
        temp->next->val = item;
        temp->next->next = nullptr;
    }
    return head;
}