#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *ptr;
};

node *head = NULL;
//
void InsertAtHead(int a){
    node *temp = new node;
    temp->data=a;
    temp->ptr = temp;
    if(head==NULL){
        head=temp;
    }
    else{
        //  40->30->20->10
        temp->ptr=head;
        node *p=head;
        while(p->ptr!=head){
            p=p->ptr;
        }
        p->ptr=temp;
        head=temp;
    }
}
//40->30->20->  15  ->10  
void InsertAnywhere(int add, int x){
    node *temp1 = new node;
    temp1->data = add;
    temp1->ptr  = NULL;
    node *p = head;
    while(p&&p->data!=x){
        p=p->ptr;
    }
    temp1->ptr = p->ptr;
    p->ptr= temp1;


}

void display(){
    node *p=head;
    while(p->ptr!=head){
        cout<<p->data<<endl;
        p=p->ptr;
    }
    cout<<p->data<<endl;
    
}
int main(){
    InsertAtHead(10);
    InsertAtHead(20);
    InsertAtHead(30);
    InsertAtHead(40);
    InsertAnywhere(15,20);
    display();
}
