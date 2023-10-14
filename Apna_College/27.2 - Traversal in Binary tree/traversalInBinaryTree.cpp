// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

// Traversal in Binary Tree.

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

/*
         1
       /  \
      2     3
     / \   / \
    4   5 6   7
*/

void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "Pre-order Traversal:" << endl;
    preOrder(root);
    cout << endl << endl;
    cout << "In-order Traversal:" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Post-order Traversal:" << endl;
    postOrder(root);

    return 0;
}