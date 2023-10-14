// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

// 2 cases are there.
// 1st in the subtree of the given node.
// 2nd going to the ancestor nodes.

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

// For Case 1:
void nodesAtKDistanceInSubTree(Node *root, int k)
{
    if (root == NULL || k < 0)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    nodesAtKDistanceInSubTree(root->left, k - 1);
    nodesAtKDistanceInSubTree(root->right, k - 1);
}

int printNodesAtK(Node *root, Node *target, int k)
{
    if (root == NULL)
        return -1;

    if (root == target)
    {
        nodesAtKDistanceInSubTree(root, k);
        return 0;
    }
    int dl = printNodesAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            nodesAtKDistanceInSubTree(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printNodesAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            nodesAtKDistanceInSubTree(root->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // printNodesAtK(root,root->left,1); // Ans: 4 1

    printNodesAtK(root, root->left, 3);

    return 0;
}