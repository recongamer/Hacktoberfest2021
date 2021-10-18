/******************************************************************************
Linked List 

*******************************************************************************/
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data =val;
        next =NULL;
    }
};
// insert at head
void insertAthead(node* &head, int val ){
    node* n=new node(val);
    n-> next= head;
    head=n;
}
// call by value
void insertAtTail(node* &head, int val){
    
    node* n=new node(val);
    //node is not in linklist
    if ( head ==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp =temp->next;
    }
    temp->next=n;
}
void display (node* head ){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next; 
        
    }
    cout<<"Null"<<endl;
}
// searching 
bool search(node* head,int key )
{ node* temp=head;
while(temp!=NULL ){
    if(temp->data==key){
        return true;
    }
    temp=temp->next;
}
return  false;
}
//deletion of node
void deletion (node* &head,int val ){
    
    if(head==NULL)//if linklist is empty
    {
        return;
    }
    if(head->next==NULL)//if there is only one linklist
    {
       deleteAtHead(head);
       return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        
        temp=temp->next;  
    }
   node* todelete =temp->next;
  temp->next =temp->next->next;
  
  delete todelete;
}
//head delete
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,4);
    insertAtTail(head,5);
    //display(head);
    insertAthead(head,6);
    display(head);
    //cout<<search(head,5)<<endl;
   // deletion(head,3);
    deleteAtHead(head);
    display(head);
    return 0;
}




