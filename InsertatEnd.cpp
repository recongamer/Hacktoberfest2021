//INSERTION ON END AND DISPLAY
#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *ptr;
};
struct node *head=NULL; 

void insert(int a){
    node *temp=new node;
    temp->data=a;
    temp->ptr=head;
    head=temp;
}
void display(){
    node *p=head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->ptr;
    }
}
void insertend(int a){
    node *add=new node;
    add->data=a;
    add->ptr=NULL;
    
    node *temp=head;
    while(temp->ptr!=NULL){
        temp=temp->ptr;
    }
    temp->ptr=add;
}
int main()
{
    insert(45);
    insert(55);
    insert(65);
    insertend(25);
    display();
}
