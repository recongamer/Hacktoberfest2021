#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data) // constructor
    {
        this->data = data;
        left = right = NULL;
    }
};

Node *findNode(Node *root, int data)
{

    if (root == NULL)
        return NULL;

    else if (data < root->data)
        return findNode(root->left, data);

    else if (data > root->data)
        return findNode(root->right, data);

    return root;
}

void insertNode(Node *root, int data)
{
    Node *temp = new Node(data);

    if (root == NULL)
        return;

    Node *par = root;
    while (par)
    {
        if (data > par->data)
        {
            if (!par->right)
            {
                par->right = temp;
                cout << "Inserted!" << endl;
                return;
            }
            else
                par = par->right;
        }

        else
        {
            if (!par->left)
            {
                par->left = temp;
                cout << "Inserted!" << endl;
                return;
            }
            else
                par = par->left;
        }
    }
}

Node *FindMax(Node *root)
{
    Node *par = root;

    while (par->right)
        par = par->right;

    return par;
}

Node *deleteNode(Node *root, int data)
{
    Node *temp;
    if (root == NULL)
        return NULL;

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else if (data < root->data)
        root->left = deleteNode(root->left, data);

    else // element found
    {
        if (root->left && root->right)
        {
            // both child
            temp = FindMax(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, root->data);
        }

        else
        {
            //single child or no child
            temp = root;
            if (root->left == NULL)
                root = root->right;

            else if (root->right == NULL)
                root = root->left;

            free(temp);
        }
    }
    return root;
}

// Recursive
Node *inOrder(Node *root)
{
    if (!root)
        return NULL;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//iterative
void inOrderiter(Node *root)
{
    Node *par = root;
    stack<Node *> st;

    while (par || !st.empty())
    {
        while (par)
        {
            st.push(par);
            par = par->left;
        }

        par = st.top();
        cout << par->data << " ";
        st.pop();

        par = par->right;
    }
}

int main()
{
    Node *root = new Node(25);

    // Hard-coded insertion.
    root->left = new Node(20);
    root->left->left = new Node(15);
    root->left->right = new Node(22);
    root->right = new Node(30);
    root->right->left = new Node(28);
    root->right->right = new Node(33);

    insertNode(root, 36);
    insertNode(root, 42);
    insertNode(root, 44);
    insertNode(root, 29);

    inOrder(root);
    cout << endl;

    deleteNode(root, 44);
    inOrder(root);
    cout << endl;
    deleteNode(root, 25);
    inOrderiter(root);

    return 0;
}