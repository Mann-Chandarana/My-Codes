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

int sumAtKthLevel(Node *root, int k)
{
    if (root == NULL)
    {
        cout << "Empty Tree ";
        return -1;
    }
    if (k == 0)
        return root->data;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int currLevel = 0, ans = 0;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (currLevel == k)
            {
                ans += node->data;
            }
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            currLevel++;
        }
    }
    return ans;
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

    cout << sumAtKthLevel(root, 0) << endl;

    return 0;
}