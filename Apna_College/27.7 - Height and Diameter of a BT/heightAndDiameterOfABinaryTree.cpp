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

int calcHeight(Node *root) // O(N)
{
    if (root == NULL)
        return 0;

    return (max(calcHeight(root->left), calcHeight(root->right)) + 1);
}

/*
    Approach 1:
int calcDiameter(Node *root) // O(N^2)
{
    if (root == NULL)
    {
        return 0;
    }

    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}
*/

// Optimal approach
int calcDiameter(Node *root, int *height) // Height and Diameter both calculated. O(N)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiamter = calcDiameter(root->left, &lh);
    int rDiamter = calcDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiamter, rDiamter));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->right->right = new Node(6);
    int height = 0;
    cout << "Height: " << calcHeight(root) << endl;
    cout << "Diameter: " << calcDiameter(root, &height) << endl;
    // cout << height << endl;

    return 0;
}