// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;
    if (leftLCA)
        return leftLCA;
    if (rightLCA)
        return rightLCA;
    return NULL;
}

int findDistance(Node *root, int k, int dis)
{
    if (root == NULL)
        return -1;

    if (root->data == k)
        return dis;

    int left = findDistance(root->left, k, dis + 1);
    if (left != -1)
        return left;

    return findDistance(root->right, k, dis + 1);
}

int distanceBetweenTwoNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);
    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1 + d2;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    cout << distanceBetweenTwoNodes(root, 4, 5) << endl;

    return 0;
}