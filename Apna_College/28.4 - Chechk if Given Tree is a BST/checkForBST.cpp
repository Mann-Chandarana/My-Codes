#include "bits/stdc++.h"
using namespace std;
#define ll long long
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Check for BST
bool isBST(Node *root, Node *min, Node *max) // O(N)
{
    if (root == NULL)
        return true;

    if (root->data <= min->data)
        return false;
    if (root->data >= max->data)
        return false;

    bool leftBST = isBST(root->left, min, root);
    bool rightBST = isBST(root->right, root, max);

    return (leftBST and rightBST);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(5);
    // root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << isBST(root, new Node(INT_MIN), new Node(INT_MAX)) << endl;

    return 0;
}