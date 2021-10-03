#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x){
        data =x;
        next = NULL;
    }
};

typedef struct Node *node;

struct Stack
{
    node head;
    int size;

    Stack()
    {
        head = NULL;
        size = 0;
    }
    //insert at end of singly linked list is push operation
    void push(int x)
    {
        node newnode = new Node(x);
        newnode->next = head;
        head = newnode;
        size++;
    }
    // delete from beginning of linked list is pop operation
    void pop()
    {
        if (head == NULL)
        {
            cout<<"Stack is empty";
            return;
        }
        else
        {
            
            node temp = head;
            head = head->next;
            delete temp;
            size--;
            
        }
    }

    bool isEmpty() { return head == NULL; }

    int stacksize() { return size; }

    int top()
    {
        if (head == NULL)
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }
};

int main()
{
    Stack s;
    // do the operations
    // s.push(10) 
    // s.push(20) 
    // s.push(30) 
    // s.push(40) 
    // s.push(50)
    // s.pop()
    // s.top()
    //s.isEmpty() 
    node temp = s.head;
    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    return 0;
}
