#include <bits/stdc++.h>
using namespace std;
template <typename T>
class binarytreenode
{
public:
    T data;
    binarytreenode *left;
    binarytreenode *right;
    binarytreenode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binarytreenode()
    {
        delete left;
        delete right;
    }
};
binarytreenode<int> *takeinput()
{
    int rootdata;
    cout << "Enter root  data" << endl;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    binarytreenode<int> *root = new binarytreenode<int>(rootdata);
    queue<binarytreenode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        binarytreenode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "ENTER LEFT CHILD OF" << front->data << endl;
        int leftchilddata;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            binarytreenode<int> *child = new binarytreenode<int>(leftchilddata);
            front->left = child;
            pendingnodes.push(child);
        }

        cout << "ENTER RIGHT  CHILD OF" << front->data << endl;
        int rightchilddata;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            binarytreenode<int> *child = new binarytreenode<int>(rightchilddata);
            front->right = child;
            pendingnodes.push(child);
        }
    }

    return root;
}

void print_tree(binarytreenode<int> *root)
{

    if (root == NULL)
        return;

    // cout << root->data << ":";

    queue<binarytreenode<int> *> pendingnodes;
    pendingnodes.push(root);

    while (pendingnodes.size() != 0)
    {

        binarytreenode<int> *front = pendingnodes.front();

        pendingnodes.pop();
        cout << front->data << ":";

        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            pendingnodes.push(front->left);
        }

        else
        {
            cout << "L:"
                 << "-1"
                 << ",";
        }
        if (front->right != NULL)
        {

            cout << "R:" << front->right->data;
            pendingnodes.push(front->right);
        }

        else
        {
            cout << "R:"
                 << "-1";
        }

        cout << endl;
    }
}
int height(binarytreenode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight, rightheight) + 1;
}
int main()
{

    binarytreenode<int> *root = takeinput();
    // print_tree(root);
    int c=height(root);
    cout<<" HEIGHT OF BINARY TREE IS :"<<c;

    return 0;
}
