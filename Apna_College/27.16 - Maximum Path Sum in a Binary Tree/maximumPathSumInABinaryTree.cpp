// #include <iostream>
#include "bits/stdc++.h"
using namespace std;
// Procedure:
// For each Node compute:
// 1. Node value.
// 2. Max path through left child + Node value.
// 3. Max path throught right child + Node value.
// 4. Max path through left child + max path through right child + node value.

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

int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);
    int nodeMax = max(max(root->data, root->data + left + right),
                      max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(-12);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(-6);

    cout << maxPathSum(root) << endl;

    return 0;
}