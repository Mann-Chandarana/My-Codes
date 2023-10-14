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

Node *insertInBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (val <= root->data)
        root->left = insertInBST(root->left, val);
    else
        root->right = insertInBST(root->right, val);

    return root;
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
    Node *root = NULL;
    int arr[] = {10, 6, 4, 9, 8, 15, 12, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        root = insertInBST(root, arr[i]);

    inOrderPrint(root);

    return 0;
}