// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

// Lowest Common Ancestor for two Nodes.

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
bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root->data);
    if (root->data == key)
        return true;
    if (getPath(root->left, key, path) || getPath(root->right, key, path))
        return true;
    path.pop_back();
    return false;
}

// In this method we first find the path from root to reach both of the nodes.
// Last common element in their path is the LCA for those two nodes.
int LCA(Node *root, int n1, int n2) // O(N)
{
    vector<int> path1, path2;

    if (!(getPath(root, n1, path1) and getPath(root, n2, path2))) // If we cannot find path1 or path2.
        return -1;

    int pc; // path change point.
    // From the example we are taking
    // path1: 1->3->5->7
    // path2: 1->3->6
    // LCA = 3. (Last coomon element in both paths).
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
            break;
    }
    return path1[pc - 1];
}

Node *LCA2(Node *root, int n1, int n2) // O(N)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLCA = LCA2(root->left, n1, n2);
    Node *rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA and rightLCA)
        return root;

    if (leftLCA != NULL)
        return leftLCA;

    if (rightLCA != NULL)
        return rightLCA;

    if (!(leftLCA and rightLCA))
        return NULL;
}

int main()
{
    /*
            1
           / \
          2   3
         /   / \
        4   5   6
             \
              7
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);

    cout << LCA(root, 7, 6) << endl;
    Node *lcaNode = LCA2(root, 7, 4);
    if (lcaNode != NULL)
        cout << lcaNode->data << endl;
    else
        cout << "Cannot find LCA" << endl;

    return 0;
}