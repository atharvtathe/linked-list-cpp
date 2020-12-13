#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};


class linkedlist
{
    private:
    node* head;
    public:
    void create();
    void display();
    void inserthead();
    void insertlast();
    void insertafter();
    void deletel();
    void search();
};

void linkedlist :: create()
{
    node *temp, *New;
    int val;
    char ans = 'y';
    bool flag = true;
    do
    {
        cout << "enter the data :";
        cin >> val;
        New = new node();
        
        New->data = val;
        New->next = NULL;
        if(flag == true)
        {
            head = New;
            temp = head;
            flag = false;
        }
        else
        {
            temp->next = New;
            temp = New;
        }
        cout << "do you want to enter more elements(y/n) :";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << "linked list created.\n";
}

void linkedlist :: display()
{
    node* temp;
    temp = head;
    if(temp == NULL)
    {
        cout << "list is empty !";
    }
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
    
}

void linkedlist :: inserthead()
{
    node *New, *temp;
    New = new node();
    cout << "enter the element to insert as head";
    cin >> New->data;
    if(head == NULL)
    {
        head = New;
    }
    else
    {
        temp = head;
        New->next = temp;
        head = New;
    }
}

void linkedlist :: insertlast()
{
    node *New, *temp;
    New = new node();
    cout << "enter the element to insert at last :";
    cin >> New->data;
    if(head == NULL)
    {
        head = New;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New;
        New->next = NULL;
    }
    
}

void linkedlist :: insertafter()
{
    int key;
    node *temp, *New;
    New = new node();
    cout << "enter the element to insert :";
    cin >> New->data;
    if(head == NULL)
    {
        head = New;
    }
    else
    {
        cout << "enter the element after which element to be inserted :";
        cin >> key;
        temp = head;
        do
        {
            if(temp->data == key)
            {
                New->next = temp->next;
                temp->next = New;
                break;
            }
            else
            {
                temp = temp->next;
            }
        } while (temp != NULL);
        
    }
    
}

void linkedlist :: deletel()
{
    node *temp, *prev;
    int key;
    temp = head;
    cout << "enter the data to be deleted";
    cin >> key;
    while (temp != NULL)
    {
        if(temp->data == key)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        cout << "node not found";
    }
    else
    {
        if(temp == head)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
        cout << "element deleted";
    }
}

void linkedlist :: search()
{
    node *temp;
    bool found;
    int key;
    temp = head;
    cout << "enter the element to search :";
    cin >> key;
    if(temp == NULL)
    {
        cout << "list is empty!";
    }
    found = false;
    while (temp != NULL && found == false)
    {
        if(temp->data != key)
        {
            temp = temp->next;
        }
        else
        {
            found = true;
            break;
        }
    }
    if(found == true)
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }   
}


int main()
{
    linkedlist ll;

    ll.create();
    ll.search();
    ll.deletel();
    ll.insertafter();
    ll.inserthead();
    ll.insertlast();
    ll.display();

    return 0;
}