#include "bits/stdc++.h"
using namespace std;

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

void calcPointers(Node *root, Node *&first, Node *&mid, Node *&last, Node *&prev) // Used reference variables.
// Traversed in In-Order manner.
{
    if (root == NULL)
        return;

    calcPointers(root->left, first, mid, last, prev);
    if (prev and root->data < prev->data)
    {
        if (!first) // Checking if this is happening for the first time.
        {
            first = prev;
            mid = root;
        }
        else // If this is happening for the second time.
        {
            last = root;
        }
    }
    prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void swap(int &a, int &b) // Passed by reference variable.
{
    int temp = a;
    a = b;
    b = temp;
}

void restoreBST(Node *root)
{
    Node *first, *mid, *last, *prev; // Used prev as temp pointer.
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, first, mid, last, prev);

    if (first and last) // For case 1.
    {
        swap(first->data, last->data);
    }
    else if (first and mid) // For case 2.
    {
        swap(first->data, mid->data);
    }
}

void inOrderPrint(Node *root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main()
{
    /*
            6
           / \
          9   3
         / \   \   
        1   4   13
    */

    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inOrderPrint(root);
    cout << endl;
    restoreBST(root);
    inOrderPrint(root);

    return 0;
}