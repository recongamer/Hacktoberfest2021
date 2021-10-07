#include<iostream>
using namespace std;

struct node{
int data;
node *next,*pre;
};

node* head=NULL;
node *tail=NULL;

void add(int n){
node *t=new node;
t->data=n;
t->next=NULL;
if(head==NULL){
head=t;
tail=t;
}
else{
t->next=head;
head=t;
t->next->pre=t;
}
}

void sort(){
node *t=tail;
for(;t->pre!=NULL;t=t->pre){
for(node *j=t->pre;j!=NULL;j=j->pre){
if(t->data>j->data){
int temp=t->data;
t->data=j->data;
j->data=temp;
}
}
}
}
void print(){
node* t=new node;
t=tail;
while(t){
cout<<t->data<<" ";
t=t->pre;
}
}
int main(){
add(6);
add(3);
add(5);
add(56);
sort();
print();

}
