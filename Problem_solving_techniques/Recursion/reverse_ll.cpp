#include <iostream>
using namespace std;
struct node
{
    int val;
    node* next;
};
void view_list(node* temp)
{
    while(temp != nullptr)
    {
        cout << temp->val<<" ";
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
node* reverse_ll(node* temp1, node* temp2)
{
    if(temp2->next == nullptr)
        {temp2->next = temp1;
        temp1->next = nullptr;
        return temp2;}
    node* temp3 = reverse_ll(temp1->next, temp2->next);
    temp2->next = temp1;
    temp1->next = nullptr;
    return temp3;
}
int main()
{   
    node* head = nullptr;
    for(int i=0; i<10; i++)
        {head = insert_at_end(head, i);}
    view_list(head);
    cout<<endl;
    head = reverse_ll(head, head->next);
    view_list(head);
    return 0;
}