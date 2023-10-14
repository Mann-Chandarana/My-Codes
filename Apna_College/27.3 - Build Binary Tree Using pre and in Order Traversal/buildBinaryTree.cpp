// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

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

int getPosition(int inOrder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == curr)
            return i;
    }
    return -1;
}

Node *buildTree(int preOrder[], int inOrder[], int start, int end) // Here start and end are for preOrder.
{
    static int idx = 0; // Used static because we need to keep same idx for every recursive functions.

    if (start > end)
        return NULL;

    int curr = preOrder[idx];
    idx++;

    Node *node = new Node(curr);
    if (start == end)
        return node;

    int pos = getPosition(inOrder, start, end, curr);
    node->left = buildTree(preOrder, inOrder, start, pos - 1);
    node->right = buildTree(preOrder, inOrder, pos + 1, end);

    return node;
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
    int preOrder[] = {1, 2, 4, 3, 5};
    int inOrder[] = {4, 2, 1, 5, 3};
    int end = (sizeof(inOrder) / sizeof(inOrder[0]) - 1);
    // Build Tree
    Node *root = buildTree(preOrder, inOrder, 0, end);

    inOrderPrint(root);

    return 0;
}