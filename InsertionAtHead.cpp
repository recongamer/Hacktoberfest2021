#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *ptr;

};

struct node *head =NULL;

void insert_head(int a){
node *temp=new node;
temp->data=a;
temp->ptr=head;
head=temp;
}    

void display(){
if(head){
    node *p=head;
    while(p!=NULL){
        cout<<"Data is :"<<p->data<<endl;
        p=p->ptr;
    }
}
else 
cout<<"Empty Linked List";
}
int main(){
int a,b,c,d;
cout<<"Enter the data you want to insert: \n";
cin>>a>>b>>c>>d;
insert_head(a);
insert_head(b);
insert_head(c);
insert_head(d);
display();
return 0;
}
