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

Node *constructBST(int preOrder[], int *preOrderIdx, int key, int min, int max, int n)
{
    if (*preOrderIdx >= n)
        return NULL;
    Node *root = NULL; // Initially declared NULL.
    if (key > min and key < max)
    {
        root = new Node(key);
        (*preOrderIdx)++;
        if (*preOrderIdx < n)
            root->left = constructBST(preOrder, preOrderIdx, preOrder[*preOrderIdx], min, key, n);
        if (*preOrderIdx < n)
            root->right = constructBST(preOrder, preOrderIdx, preOrder[*preOrderIdx], key, max, n);
    }
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
    /*
            10
           /  \
          2    13
         /     /
        1     11
    */

    int preOrder[] = {10, 2, 1, 13, 11};
    int preOrderIndex = 0;
    Node *root = constructBST(preOrder, &preOrderIndex, preOrder[0], INT_MIN, INT_MAX, sizeof(preOrder) / sizeof(preOrder[0]));
    inOrderPrint(root);
    cout << endl;

    return 0;
}