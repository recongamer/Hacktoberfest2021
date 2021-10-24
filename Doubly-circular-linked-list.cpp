#include<iostream>
using namespace std;
int a=0;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *first;
struct node *last;

void insert_node_at_first()
{
    struct node *nn;
    nn=(struct node *)malloc(sizeof(struct node));
    int d;
    cout<<"Enter the value: "<<endl;
    cin>>d;
    nn->data=d;
    if (first==NULL)
    {
        first=nn;
        first->prev=nn;
        first->next=nn;
        last=nn;
    }
    else
    {
       nn->next=first;
       nn->prev=last;
       first->prev=nn;
       first=nn;
       last->next=nn;

    }
    cout<<"Element Inserted successfully!!"<<endl;
    a++;
}
void insert_node()
{
    struct node *nn;
    nn=(struct node *)malloc(sizeof(struct node));
    int d;
    cout<<"Enter the value: "<<endl;
    cin>>d;
    nn->data=d;
    if (first==NULL)
    {
        first=nn;
        first->prev->next=nn;
        last=nn;
    }
    else
    {
        nn->prev=last;
        nn->next=last->next;
        last->next=nn;
        first->prev=nn;
        last=nn;

    }
    cout<<"Element Inserted successfully!!"<<endl;
    a++;
}
void insert_node_after_element()
{
    struct node *nn;
    nn=(struct node *)malloc(sizeof(struct node));
    int d;
    cout<<"Enter the value of new node: "<<endl;
    cin>>d;
    nn->data=d;
    if (first==NULL)
    {
        first=nn;
        first->prev->next=nn;
        last=nn;
        cout<<"Element Inserted successfully!!"<<endl;

    }
    else
    {
        int ele;
        cout<<"Enter the node after which you have to insert element : "<<endl;
        cin>>ele;
        int c=0;
       struct node *temp,*temp1;
       temp=first;
       while(temp->data!=ele)
       {
           if(temp->next==NULL)
           {
               cout<<"Invalid operation :Please enter right value"<<endl;
               c=1;
               break;
           }

           temp=temp->next;
       }
       if(c!=1)
       {
           if(a==1)
           {
               temp->next->prev=nn;
               nn->prev->next=temp;

           }
           else
           {
               nn->next=temp->next;
               nn->prev=temp;
               temp->next=nn;
               temp1=nn->next;
               temp1->prev=nn;
           }
           cout<<"Element Inserted successfully!!"<<endl;
           a++;

       }


    }
}
void remove_first()
{
    if(a==0)
    {
        cout<<"Doubly Circular linked list is empty"<<endl;
    }
    else
    {
        struct node *temp;
        temp=first;
        first=first->next;
        last->next=first;
        first->prev=temp->prev;
        cout<<temp->data<<" removed Successfully"<<endl;
        free(temp);
        a--;
    }

}
void remove_last()
{
       if(a==0)
    {
        cout<<"Doubly Circular linked list is empty"<<endl;
    }
    else
    {
        struct node *temp;
        temp=last;
        last=last->prev;
        last->next=first;
        first->prev=last;
        cout<<temp->data<<" removed Successfully"<<endl;
        free(temp);
        a--;
    }

}
void remove_select()
{
  if(a==0)
  {
       cout<<"Doubly Circular linked list is empty"<<endl;
  }
  else
  {
      int ele;
    cout<<"Enter the element you want to remove: "<<endl;
    cin>>ele;
    struct node *temp;
    temp=first;
    while(temp->data!=ele)
    {
        temp=temp->next;
    }
    if(temp==first)
    {
        struct node *temp1,*temp2;
        first=first->next;
        temp1=temp->prev;
        temp2=temp->next;
        temp2->prev=last;
        temp1->next=temp->next;
        cout<<"Element "<<temp->data<<" removed succesfully!1"<<endl;
        free(temp);
    }
    else
    {
         struct node *temp1,*temp2;
        temp1=temp->prev;
        temp2=temp->next;
        temp1->next=temp->next;
        temp2->prev=temp->prev;
        cout<<"Element "<<temp->data<<" removed succesfully!1"<<endl;
        free(temp);
    }
    a--;
  }
}
void display()
{
    if(a==0)
    {
        cout<<"Doubly Circular linked list is empty"<<endl;
    }
    else{
        struct node *temp;
        temp=first;
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=first);
    }
}
 void remove()
{
    int i;
    do
    {
        cout<<endl;
        cout<<"================Remove Menu==========="<<endl;
        cout<<"1-Remove element from First "<<endl;
        cout<<"2-Remove element from Last"<<endl;
        cout<<"3-Remove selected element "<<endl;
        cout<<"4-Main Menu"<<endl;
        cout<<"Provide your choice :"<<endl;
        cin>>i;
        switch(i)
        {
         case 1:
            remove_first();
            display();
            break;
         case 2:
            remove_last();
            display();
            break;
         case 3:
            remove_select();
            display();
            break;
        }
    }while(i!=4);
}
void insert()
{
     int i;
    do
    {
        cout<<endl;
        cout<<"================Remove Menu==========="<<endl;
        cout<<"1-Insert element from First "<<endl;
        cout<<"2-Insert element from Last"<<endl;
        cout<<"3-Insert selected element "<<endl;
        cout<<"4-Main Menu"<<endl;
        cout<<"Provide your choice :"<<endl;
        cin>>i;
        switch(i)
        {
            case 1:
            insert_node_at_first();
            display();
            break;
          case 2:
            insert_node();
            display();
            break;
         case 3:
            insert_node_after_element();
            display();
            break;
        }
    }while(i!=4);

}
int main()
 {
     first=NULL;
     int i;
     do
     {
         cout<<endl;
         cout<<"=========MENU============"<<endl;
         cout<<"1-Insert element "<<endl;
         cout<<"2-Remove element "<<endl;
         cout<<"3-Display Linked List"<<endl;
         cout<<"Provide your choice :"<<endl;
         cin>>i;
         switch(i)
         {
         case 1:
            insert();
            break;
        case 2:
            remove();
            break;
        case 3:
            display();
            break;


         }
     }while(true);
 }
