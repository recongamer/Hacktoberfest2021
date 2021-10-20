#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int v){
        data=v;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void insertAtPosition(node* &head, int val, int p){
    node* cur=head;
    node* temp=new node(val);
    node* pre;
    while(p--){
        pre=cur;
        cur=cur->next;
    }
    pre->next=temp;
    temp->next=cur;
}

void insertAtTail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp= head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n;
}

void printlist(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL\n";
}

int main(){
    node* head=NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    
    insertAtTail(head,5);
    insertAtTail(head,6);
 
    insertAtPosition(head,3,3);
    insertAtPosition(head,4,4);
    printlist(head);
}
