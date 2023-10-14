// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

// After flattening the tree, each nodes' left node should become NULL and tree should be in pre-order sequence,
// with right node connecting each element with its next element.

// 1. Recursievly flatten the left and the right sub tree.
// 2. Store the left tail(Last element of left flatten sub tree of the node) and the right tail.
// 3. Store the right subtree in temp and make left sub tree as right subtree.
// 4. Join right sub tree with left tail.
// 5. return right tail. // IMP.
// Here getting right tail (From step 2) and returning right tail is useful when we make a function with Node* return type.

/*
         1
       /   \
      2     3
       \   / \
       4  5   6

    Answer: 1
             2
              4
               3
                5
                 6
*/

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL and root->right == NULL)) // Base condition.
        return;

    if (root->left != NULL)
    {
        flatten(root->left);      // Step 1.
        Node *temp = root->right; // Step 3.
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL) // For getting to the left tail described in the procedure.
        // Here t->right is taken because in the previous step we moved the left flatten sub tree to the right node of the root.
        {
            t = t->right;
        }
        t->right = temp; // Step 4.
    }

    flatten(root->right);
}

void inOrderPrint(Node *root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

void preOrderPrint(Node *root)
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
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    preOrderPrint(root);
    cout << endl;
    flatten(root);
    inOrderPrint(root);

    return 0;
}