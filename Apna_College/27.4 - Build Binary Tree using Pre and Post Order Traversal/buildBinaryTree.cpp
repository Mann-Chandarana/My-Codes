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
        if (inOrder[i] == curr)
            return i;

    return -1;
}

Node *buildBinaryTree(int postOrder[], int inOrder[], int start, int end)
{
    static int idx = end;
    if (start > end)
        return NULL;
    int curr = postOrder[idx];
    idx--;
    Node *node = new Node(curr);

    if (start == end)
        return node;

    int pos = getPosition(inOrder, start, end, curr);
    node->right = buildBinaryTree(postOrder, inOrder, pos + 1, end);
    node->left = buildBinaryTree(postOrder, inOrder, start, pos - 1);

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
    int postOrder[] = {4, 2, 5, 3, 1};
    int inOrder[] = {4, 2, 1, 5, 3};
    int end = (sizeof(postOrder) / sizeof(postOrder[0]) - 1);

    Node *root = buildBinaryTree(postOrder, inOrder, 0, end);
    inOrderPrint(root);

    return 0;
}