#include "bits/stdc++.h"
using namespace std;
// No duplicate nodes are there in BST.
// Even though we insert k more than once, we only get one k in the BST.
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

void insertInBinarySearchTree(Node *&root, int val)
{
    Node *n = new Node(val);
    if (root == NULL)
    {
        root = n;
        return;
    }
    // if (root->left == NULL and val < root->data)
    // {
    //     root->left = n;
    //     return;
    // }
    // if (root->right == NULL and val > root->data)
    // {
    //     root->right = n;
    //     return;
    // }
    if (val == root->data) // To avoid duplicates in BST.
        return;
    if (val < root->data)
        insertInBinarySearchTree(root->left, val);
    else
        insertInBinarySearchTree(root->right, val);
}
 // In-order traverse of a BST always gives us a sorted order.
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
    Node *root = NULL;
    int arr[] = {10, 6, 4, 9, 8, 4, 15, 12, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        insertInBinarySearchTree(root, arr[i]);

    inOrderPrint(root);
    cout << endl;

    return 0;
}