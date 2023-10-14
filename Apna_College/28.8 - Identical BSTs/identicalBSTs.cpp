#include "bits/stdc++.h"
using namespace std;

// This can be used for normal trees also.

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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL and root2 == NULL) // If both are NULL.
        return true;
    else if (root1 == NULL or root2 == NULL) // If either tree1 or tree2 dosen't have that ST.
        return false;

    // Both the trees have that ST.
    bool sameVal = root1->data == root2->data;
    // (root1->data == root2->data) ? sameVal = true : sameVal = false;
    bool leftIdentical = isIdentical(root1->left, root2->left);
    bool rightIdentical = isIdentical(root1->right, root2->right);

    if (sameVal and (leftIdentical and rightIdentical))
        return true;
    else
        return false;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->right = new Node(4);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->right = new Node(4);
    root2->right->left = new Node(5);

    cout << isIdentical(root1, root2) << endl;

    return 0;
}