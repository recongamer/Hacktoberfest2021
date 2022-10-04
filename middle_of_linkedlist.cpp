#include<bits/stdc++.h>
using namespace std;
int counte = 0;

struct node {
    int data;
    struct node *next;
};

struct node * create_node(int data){
    struct node *p= (struct node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

void insert_node(struct node* head,int position,int info){
    position--;
    counte++;
    struct node * p = create_node(info);
    struct node* it = head;
    while(position-->0){
          it=it->next;
    }
    p->next = it->next;
    it->next = p;
}

void return_middle(node* head,int node_size){
    int k = ceil(node_size/2);
    node *it = head;
    while(k--){
        it=it->next;
    }
    cout<<"Middle node is: "<<it->data<<endl;
}

void display(struct node *head){
    struct node *it = head;
    while(it->next != NULL){
        cout<<it->data<<"-";
        it=it->next;
    }
    cout<<it->data<<endl;
}



int main()
{    
    
    struct node *head = (struct node*)malloc(sizeof(node));
    head->data = 10;
    head->next = NULL;

    insert_node(head,1,5);

    insert_node(head,2,6);
    insert_node(head,3,7);
    insert_node(head,4,19);

    int node_size = counte;

    return_middle(head,5);
    
    // display(head);
    return 0;
}
