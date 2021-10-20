#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int d) {
        data = d;
        next = NULL;
    }
};
void insertAtHead(node* &head, int value) {
    node* temp = new node(value);
    if(head == NULL) {
        head = temp;
        return;
    }
    node* curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
}
void printList(node* head) {
    node* curr = head;
    while(curr != NULL) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
node* reverse(node* &head) {
    node* prev = NULL;
    node* curr = head;
    node* next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}  
int main()
{
    int n;
    cout<<"Enter the number of nodes in the linked list:";
    cin>>n;
    int x;
    cout<<"Enter the nodes:";
    cin>>x;
    node* head = new node(x);
    for(int i=1;i<n;i++) {
        cin>>x;
        insertAtHead(head,x);
    }
    cout<<"The Original Linked List is: ";
    printList(head);
    head = reverse(head);
    cout<<"The Linked List after reversal is: ";
    printList(head);
    return 0;
}
