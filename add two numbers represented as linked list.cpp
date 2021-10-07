/* You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.*/

#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* newNode(int data)
{
    ListNode* new_node = new ListNode();
    new_node->val = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node at the beginning of the Singly Linked List */
void push(ListNode** head_ref, int new_data)
{
    /* allocate node */
    ListNode* new_node = newNode(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

//function to add the linked list values
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1,*temp2=l2;
        ListNode* head=NULL,*tail=NULL;
        
        int sum=temp1->val+temp2->val;
        int rem=sum%10;
        int carry=sum/10;
        
        head=tail=new ListNode(rem);
  
        temp1=temp1->next;
        temp2=temp2->next;
        while(temp1!=NULL ||  temp2!=NULL){
            int a = (temp1) ? temp1->val : 0;
            int b = (temp2) ? temp2->val : 0;
            sum = a + b + carry;
            rem = sum % 10;
            carry = sum/10;
            
            tail->next = new ListNode(rem);
            tail = tail->next;
            if(temp1)
                temp1=temp1->next;
            if(temp2)
                temp2=temp2->next;
        }
        while(carry)
        {
            tail->next=new ListNode(carry%10);
            tail=tail->next;
            carry/=10;
        }
        return head;
}

//function to reverse the list
ListNode* reverse(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
 
    /* reverse the rest list and put the first element at the end */
    ListNode* rest = reverse(head->next);
    head->next->next = head;
 
    head->next = NULL;
 
    /* fix the head pointer */
    return rest;
}  

//print the list
void printList(ListNode* node)
{
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}


/* Driver code */
int main()
{
    ListNode* res = NULL;
    ListNode* first = NULL;
    ListNode* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    cout << "Second List is ";
    printList(second);
 
    // reverse both the lists
    first = reverse(first);
    second = reverse(second);
    // Add the two lists
    res = addTwoNumbers(first, second);
 
    // reverse the res to get the sum
    res = reverse(res);
    cout << "Resultant list is ";
    printList(res);
 
    return 0;
}

// Time Complexity: O(n+m) where n is number of nodes l1 and m is number of nodes in l2
