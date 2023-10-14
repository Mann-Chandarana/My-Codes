#include "bits/stdc++.h"
using namespace std;

// Binary Search Tree should be balanced.
// Height balanced BST: For every node |height(LeftST) - height(RightST)| <= 1.

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

Node *BSTFromSortedArray(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = BSTFromSortedArray(arr, start, mid - 1);
    root->right = BSTFromSortedArray(arr, mid + 1, end);

    return root;
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
    int sortedArr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(sortedArr) / sizeof(sortedArr[0]);
    Node *root = BSTFromSortedArray(sortedArr, 0, n - 1);
    preOrderPrint(root);

    return 0;
}