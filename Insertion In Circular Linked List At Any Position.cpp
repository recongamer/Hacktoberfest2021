#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
struct node *start = NULL;
struct node *last = NULL;
void insert(int data)
{
    struct node *ptr=new node;
    ptr->data=data;
    if(start==NULL)
    {
        start=ptr;
        last=ptr;
        start->next=ptr;
    }
    else
    {
        last->next=ptr;
        last=ptr;
        ptr->next=start;
    }
}

void display()
{
    struct node *temp;
    temp=start;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=start);
}

void insert_node(int key,int pos)    //Insertion in Circular linked list at any position
{
    struct node *temp=new node;
    struct node *ptr;
    int count=0;
    temp->data=key;
    ptr=start;
    do
    {
        if(pos==0)
        {
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->next=start;
            start=temp;
            break;
        }
        else if(count==pos-1)
        {
            temp->next=ptr->next;
            ptr->next=temp;
            break;
        }
        count++;
        ptr=ptr->next;
    }while(ptr!=start);
    
}

int main()
{
    int i,n,a,b,pos;
    for(i=0;i<10;i++)
    {
        insert(i+10);
    }
    cout<<"Displaying circular linked list : ";
    display();
    cout<<"\nEnter the element you want to insert : ";
    cin>>a;
    cout<<"Enter the position you want to insert (taking first node at 0 position) : ";
    cin>>pos;
    insert_node(a,pos);
    cout<<"\nDisplaying circular linked list after insertion : ";
    display(); 
    return 0;
}
