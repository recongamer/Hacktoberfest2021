#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long unsigned llu;

struct TreeNode
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

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
    {
        cout << "No search element exists.";
        return NULL;
    }

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

Node *inOrder(Node *root)
{
    if (!root)
        return NULL;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// First Method
bool isBST1(Node *root, int minValue, int maxValue)
{
    // Time Complexity O(N)
    if (root == NULL)
        return true;

    if (root->data >= minValue && root->data <= maxValue && isBST1(root->left, minValue, root->data) && isBST1(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

//Second Method  (By twiking inorder method)
bool isBST2(Node *root)
{
    static Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST2(root->left))
            return false;

        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;
        return isBST2(root->right);
    }

    else
        return true;
}

int main()
{
    Node *root = new Node(25);

    // Hard-coded insertion.
    root->left = new Node(15);
    root->left->right = new Node(22);
    root->right = new Node(30);
    root->right->left = new Node(28);
    root->right->right = new Node(33);

    insertNode(root, 15);
    insertNode(root, 28);
    // insertNode(root, 33);
    // insertNode(root, 29);

    inOrder(root);
    cout << endl;

    deleteNode(root, 15);

    inOrder(root);
    cout << endl;
    deleteNode(root, 28);

    inOrder(root);
    cout << endl;
    if (isBST2(root))
        cout
            << "BST";
    else
        cout << "NOT BST";

    return 0;
}