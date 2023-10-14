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

Node *buildBinaryTree(int arr[], int start, int end)
{
    if (start > end)
        return NULL;
    if (start == end)
        return new Node(arr[start]);

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = buildBinaryTree(arr, start, mid - 1);
    root->right = buildBinaryTree(arr, mid + 1, end);

    return root;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapifyANode(Node *&root) // Max Heap // O(log N)
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
                heapifyANode(root->right);
            }
            else
            {
                swap(root->data, root->left->data);
                heapifyANode(root->left);
            }
        }
    }
    else if (root->left and root->right == NULL)
    {
        if (root->data < root->left->data)
        {
            swap(root->data, root->left->data);
            heapifyANode(root->left);
        }
    }
    else if (root->right and root->left == NULL)
    {
        if (root->data < root->right->data)
        {
            swap(root->data, root->right->data);
            heapifyANode(root->right);
        }
    }
    return;
}

void heapifyATree(Node *&root) // Max heap // O(N)
{
    if (root == NULL)
        return;
    if (root->left == NULL and root->right == NULL) // Leaf node.
        return;
    if (root->left)
        heapifyATree(root->left);
    if (root->right)
        heapifyATree(root->right);

    heapifyANode(root);
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
    int arr[] = {3, 6, 5, 0, 8, 2, 1, 9};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;

    Node *root = buildBinaryTree(arr, start, end);
    preOrderPrint(root);
    cout << endl;

    heapifyATree(root);
    preOrderPrint(root);
    cout << endl;

    return 0;
}