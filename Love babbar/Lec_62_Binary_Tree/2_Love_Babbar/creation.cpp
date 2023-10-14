#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *creation(Node *&root)
{
    int val;
    if (root == NULL)
    {
        cout << "Enter the data for this node: ";
        cin >> val;
        root = new Node(val);
    }
    else
    {
        val = root->data;
    }

    cout << "Do you want to create the left chil of " << val << " (y/n)? ";
    char ch;
    cin >> ch;

    if (ch == 'n')
        root->left = NULL;
    else
        root->left = creation(root->left);

    cout << "Do you want to create the right chil of " << val << " (y/n)? ";
    cin >> ch;

    if (ch == 'n')
        root->right = NULL;
    else
        root->right = creation(root->right);

    return root;
}

void inOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main()
{
    // Node *root = NULL;
    Node *root = new Node(1);

    creation(root);

    inOrderTraversal(root);
    /*
        Other traversals are included in myCode.cpp
    */


    return 0;
}