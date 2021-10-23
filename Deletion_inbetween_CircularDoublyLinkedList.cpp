#include <iostream>
using namespace std;
struct node{
    int data;
    node *ptr,*pre;
};
node *head=NULL;
void insertathead(int a){
    node *temp=new node;
    temp->data=a;
    temp->ptr=temp->pre=temp;
    if(head==NULL)
        head=temp;
    else{
        temp->ptr=head;
        temp->pre=head->pre;
        head->pre=temp;
        temp->pre->ptr=temp;
        head=temp;
    }
}
void deletionatBtwn(int x){
    if(head==NULL)
        cout<<"Empty\n";
    else{
        node *p=head;
        while(p->ptr!=head && p->data!=x)
            p=p->ptr;
        if(p->data!=x)
            cout<<"Ref Element not found\n";
        else if(p->ptr==p)
            head=NULL;
        else{
            p->ptr->pre=p->pre;
            p->pre->ptr=p->ptr;
            if(head==p)
                head=head->ptr;
        }
        p=NULL;
    }
}
void display(){
    node *p=head;
    while(p->ptr!=head){
        cout<<p->data<<endl;
        p=p->ptr;
    }
    cout<<p->data<<endl;
}
int main()
{
    insertathead(50);
    insertathead(40);
    insertathead(30);
    insertathead(20);
    insertathead(10);
    display();
    cout<<"After Deletion\n";
    deletionatBtwn(30);
    display();
    return 0;
}
