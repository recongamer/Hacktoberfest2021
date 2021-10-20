#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

bool isSameTree(TreeNode *root, TreeNode *subRoot)
{
    if (root == NULL || subRoot == NULL)
        return root == NULL && subRoot == NULL;

    else if (root->val == subRoot->val)
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);

    else
        return false;
}

bool isSubTree(TreeNode *root, TreeNode *subRoot)
{
    if (root == NULL)
        return false;
    else if (isSameTree(root, subRoot))
        return true;
    else
        isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *subRoot = new TreeNode(4);

    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    // root->left->right->left = new TreeNode(0);   // for false.

    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    if (isSubTree(root, subRoot))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}