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
        right = NULL;
        left = NULL;
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
    return NULL; // This return NULL is for, if we cannot find any LCA for given to nodes.
    // Which means either of the nodes or both of the nodes are not present in the tree.
}

bool getDistance(Node *root, int n1, int &dis)
{
    if (root == NULL)
        return false;
    if (root->data == n1)
    {
        return true;
    }
    if (getDistance(root->left, n1, dis))
    {
        dis++;
        return true;
    }
    if (getDistance(root->right, n1, dis))
    {
        dis++;
        return true;
    }
    return false; // This return flase is for, if n1 is not present in BT.
}

// Shortest distance between two nodes passes form their LCA.
// Shortest distance is distance(LCA to Node with data as n1) + disstancer(LCA to node with data as n2).
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->right = new Node(7);

    int nodeData1 = 7, nodeData2 = 4;
    Node *lcaNode = LCA(root, nodeData1, nodeData2);
    int distance1 = 0;
    int distance2 = 0;
    if (getDistance(lcaNode, nodeData1, distance1) and getDistance(lcaNode, nodeData2, distance2))
        cout << distance1 + distance2 << endl;
    else
        cout << "Cannot find the distance" << endl;

    return 0;
}