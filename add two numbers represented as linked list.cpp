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


/* insert a node at the beginning */
void push(ListNode** head_ref, int new_data)
{
    /* allocate node */
    ListNode* dummy = new ListNode(new_data);
    dummy->next = (*head_ref);
    (*head_ref) = new_node;  //making this node as head
}

//function to add the linked list values
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1,*temp2=l2;
        ListNode* head=NULL,*tail=NULL;
        
        int sum = temp1->val + temp2->val;
        int rem = sum%10;
        int carry = sum/10;
        
        head=tail=new ListNode(rem);
  
        temp1=temp1->next;
        temp2=temp2->next;
        //until either of the lists are not empty
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
         //if carry is not empty till now add its values as nodes of linked list
        while(carry)
        {
            tail->next=new ListNode(carry%10);
            tail=tail->next;
            carry/=10;
        }
        return head;
}
//iterative function for reversing the linked list
ListNode* reverse(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(current!=NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
}


//print the list
void print(ListNode* head)
{
    ListNode* temp=head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


/* Driver code */
int main()
{
    ListNode* result = NULL;
    ListNode* firstList = NULL;
    ListNode* secondList = NULL;
 
    // create first list 
    push(&firstList, 1);
    push(&firstList, 1);
    push(&firstList, 9);
    push(&firstList, 7);
    push(&firstList, 3);
    printf("First List is ");
    printList(firstList);
  
    // create second list 
    push(&secondList, 4);
    push(&secondList, 8);
    cout << "Second List is ";
    printList(secondList);
 
    // reverse both the lists
    firstList = reverse(firstList);
    secondList = reverse(secondList);
    // Add the two lists
    result = addTwoNumbers(firstList, secondList);
 
    // reverse the res to get the sum
    result = reverse(result);
    cout << "Resultant list is ";
    printList(result);
 
    return 0;
}

// Time Complexity: O(n+m) where n is number of nodes l1 and m is number of nodes in l2
