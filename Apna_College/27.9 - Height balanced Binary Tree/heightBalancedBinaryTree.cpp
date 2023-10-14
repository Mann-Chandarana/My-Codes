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

int height(Node *root) // O(N)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (max(lh, rh) + 1);
}
/*
bool isBalanced(Node *root) // O(N^2)
{
    if (root == NULL)
        return true;

    if (isBalanced(root->left) == false)
        return false;
    if (isBalanced(root->right) == false)
        return false;

    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}
*/
// Optimal Approach
bool isBalanced(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (isBalanced(root->left, &lh) == false)
        return false;
    if (isBalanced(root->right, &rh) == false)
        return false;
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
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
    int height = 0;
    cout << isBalanced(root, &height) << endl;

    return 0;
}