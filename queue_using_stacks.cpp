/* Author : Neetu Singh */

/*  Below program is written in C++ language  */

# include<iostream>

using namespace std;

// implementing the stack class
class Stack
{
    int top;
    public:
    int a[10];  //Maximum size of Stack
    Stack()
    {
        top = -1;
    }
    
    // declaring all the function
    void push(int x);
    int pop();
    bool isEmpty();
};

// function to insert data into stack
void Stack::push(int x)
{
    if(top >= 10)
    {
        cout << "Stack Overflow \n";
    }
    else
    {
        a[++top] = x;
        cout << "Element Inserted into Stack\n";
    }
}

// function to remove data from the top of the stack
int Stack::pop()
{
    if(top < 0)
    {
        cout << "Stack Underflow \n";
        return 0;
    }
    else
    {
        int d = a[top--];
        return d;
    }
}

// function to check if stack is empty
bool Stack::isEmpty()
{
    if(top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// implementing the queue class
class Queue {
    public:
    Stack S1, S2;
    
    //declaring enqueue method
    void enqueue(int x);
    
    //declaring dequeue method
    int dequeue();
};

// enqueue function
void Queue :: enqueue(int x) 
{
    S1.push(x);
    cout << "Element Inserted into Queue\n";
}

// dequeue function
int Queue :: dequeue() 
{
    int x, y;
    while(!S1.isEmpty()) 
    {
        // take an element out of first stack
        x = S1.pop();
        // insert it into the second stack
        S2.push(x);
    }
  
    // removing the element
    y = S2.pop();
  
    // moving back the elements to the first stack
    while(!S2.isEmpty()) 
    {
        x = S2.pop();
        S1.push(x);
    }
  
    return y;
}

// main function
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(1000);
    cout << "Removing element from queue" << q.dequeue();
    
    return 0;
}