#include "bits/stdc++.h"
using namespace std;

// To heapify ith element, all the elements in both left and right STs must follow heap properties.
// That is both the STs must be heaps individually.

// Max heap:

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(Node *&root) // O(log N)
{
    if (root->left == NULL and root->right == NULL)
        return;

    if (root->right != NULL and root->left != NULL)
    {
        if ((root->data < root->left->data) and (root->data < root->right->data))
        {
            if (root->right->data > root->left->data)
            {
                swap(root->data, root->right->data);
                heapify(root->right);
            }
            else
            {
                swap(root->data, root->left->data);
                heapify(root->left);
            }
        }
    }
    else if (root->left and root->right == NULL)
    {
        if (root->data < root->left->data)
        {
            swap(root->data, root->left->data);
            heapify(root->left);
        }
    }
    else if (root->right and root->left == NULL)
    {
        if (root->data < root->right->data)
        {
            swap(root->data, root->right->data);
            heapify(root->right);
        }
    }
    return;
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
    Node *root = new Node(6);
    root->left = new Node(100);
    root->right = new Node(50);
    root->left->left = new Node(10);
    root->left->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(5);

    preOrderPrint(root);
    cout << endl;
    heapify(root);
    // Condition: left ST and right ST is aleary a heap.
    // This is for max heap.

    preOrderPrint(root);
    cout << endl;

    return 0;
}