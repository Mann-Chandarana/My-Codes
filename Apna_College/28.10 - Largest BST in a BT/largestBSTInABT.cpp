#include "bits/stdc++.h"
using namespace std;

// Return the size of the largest Binary Search Tree in a normal tree.

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

// Initial access specifier in strcut is public.
class Info
{
public:
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true}; // It's not a constructor. We have typecasted the list into class Info.
    }

    if (root->left == NULL and root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if (leftInfo.isBST and rightInfo.isBST and (leftInfo.max < root->data) and (rightInfo.min > root->data))
    {
        curr.min = min(leftInfo.min, min(root->data, rightInfo.min));
        curr.max = max(rightInfo.max, max(root->data, leftInfo.max));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    // Info info = largestBSTinBT(root);
    // cout << info.ans << endl;

    cout << "Largest BST in BT: " << largestBSTinBT(root).ans << endl;

    return 0;
}