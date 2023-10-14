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

// We use queue for level order traversal.
void levelOrderPrint(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        if (q.front())
            cout << node->data << " ";
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);

        if (!q.front())
        {
            q.pop(); // Here we pop NULL pointer in the same loop. Because in the next loop if there is a NULL pointer,
            // then we cannot access its right or left child.
            if (!q.empty())
                q.push(NULL);
        }
    }
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

    levelOrderPrint(root);

    return 0;
}