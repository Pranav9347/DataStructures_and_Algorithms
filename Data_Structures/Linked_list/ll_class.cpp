#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* next;
}node;

class Linked_list
{
    private:
    node* head;
    int size;

    public:
    Linked_list():head{nullptr}, size{0}{}
    void view_list();
    int get_size(){return size;}
    void insert_at_beginning(int item);
    void insert_at_pos(int item, int pos);
    void insert_at_end(int item);
    void delete_at_beginning();
    void delete_at_pos(int pos); 
    void delete_at_end();
    
};

int main()
{   
    Linked_list A;
    for(int i=0; i<5; i++){
        A.insert_at_beginning(i);
    }
    A.view_list();
    cout << A.get_size()<<endl;

    A.delete_at_pos(3);
    A.view_list();
    A.insert_at_pos(8,1);
    A.view_list();

    A.delete_at_end();
    A.view_list();
    return 0;
}

void Linked_list::view_list()
{
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->val;
        temp = temp->next;
    }
    cout << endl;
}

void Linked_list::insert_at_beginning(int item)
{
    node* temp = new node;
    temp->val = item;
    temp->next = head;
    head = temp;
    size++;
}

void Linked_list::insert_at_pos(int item, int pos)
{
    if(pos == 1)
    {
        insert_at_beginning(item);
        size++;
        return;
    }
    else
    {
        node* temp = head;
        node* new_node = new node;
        new_node->val = item;
        for(int i=0; i < pos-2; i++)
        {
            if(temp == nullptr)
            {
                cout << "Invalid position!\n";
                return;
            }
            temp = temp->next;
        }
        
        new_node->next = temp->next;
        temp->next = new_node;
        size++;
    }
}

void Linked_list::insert_at_end(int item)
{
    node* temp = head;
    if(temp == nullptr)
    {
        insert_at_beginning(item);
        size++;
        return;
    }
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    node* new_node = new node;
    new_node->val = item;
    temp->next = new_node;
    new_node->next = nullptr;
    size++;
}

void Linked_list::delete_at_beginning()
{
    if(head == nullptr)
        return;
    node* temp = head->next;
    delete head;
    head = temp;
    size--;
}

void Linked_list::delete_at_pos(int pos)
{
    if(head == nullptr)
        return;
    if(pos == 1)
    {
        delete_at_beginning();
        size--;
        return;
    }
    node* temp = head;
    for(int i=0; i<pos-2; i++)
    {
        if(temp == nullptr || temp->next == nullptr)
        {
            cout << "Invalid position!\n";
            return;
        }
        temp = temp->next;
    }
    
    node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    size--;
}

void Linked_list::delete_at_end()
{
    if(head == nullptr)
        return;
    node* temp = head;
    if(temp->next == nullptr)
    {
        delete_at_beginning();
        size--;
        return;
    }
    while(temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    size--;
}