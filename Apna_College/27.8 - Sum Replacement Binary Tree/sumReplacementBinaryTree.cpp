// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void sumReplacement(Node *root) // O(N)
{
    if (root == NULL)
        return;

    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left != NULL)
        root->data += root->left->data;

    if (root->right != NULL)
        root->data += root->right->data;
}

void preOrderPrint(Node *root) // O(N)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrderPrint(root);
    cout << endl;
    sumReplacement(root);
    preOrderPrint(root);

    return 0;
}