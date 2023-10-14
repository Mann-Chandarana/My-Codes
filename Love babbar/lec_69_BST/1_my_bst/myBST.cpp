#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void insert(Node *&root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return;
    }

    if (data <= root->data)
    {
        insert(root->left, data);
    }
    else
        insert(root->right, data);
}

/*
Node* insert(Node *root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return root;
    }

    if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
        root->right = insert(root->right, data);
    
    return root;
}
*/

void preOrder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Get max: Go right till leaf node
// Get min: Go left till leaf node

int main()
{
    Node *root = NULL;

    int n; // 8
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        insert(root, temp);
    }
    // 10 8 21 7 27 5 4 3

    preOrder(root);

    return 0;
}