#include <bits/stdc++.h>
using namespace std;

// Leetcode 173 for best approach


class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void iterator(Node *root)
{
    
}

int main()
{

    Node *root = new Node(7);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->left->left = new Node(4);
    root->right = new Node(10);
    root->right->left = new Node(9);
    root->right->left->left = new Node(8);


    return 0;
}