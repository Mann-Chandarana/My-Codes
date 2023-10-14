#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// O(N)
void zigZagTraversal(Node *root) // My code
{
    if (root == NULL)
        return;

    bool leftToRight = true;
    stack<Node *> currLevel, nextLevel;
    currLevel.push(root);

    while (!currLevel.empty())
    {
        while (!currLevel.empty())
        {
            if (currLevel.top()) // NULL or not.
                cout << currLevel.top()->data << " ";

            if (currLevel.top() and leftToRight) // if NULL then we cannot access its children.
            {
                if (currLevel.top()->left)
                    nextLevel.push(currLevel.top()->left);
                if (currLevel.top()->right)
                    nextLevel.push(currLevel.top()->right);
            }
            else if (currLevel.top() and !leftToRight)
            {
                if (currLevel.top()->right)
                    nextLevel.push(currLevel.top()->right);
                if (currLevel.top()->left)
                    nextLevel.push(currLevel.top()->left);
            }
            currLevel.pop();
        }
        leftToRight = !leftToRight;

        swap(currLevel, nextLevel);
    }
}

void zigZagTraversal2(Node *root) // Apna college method
{
    if (root == NULL)
        return;

    stack<Node *> currLevel, nextLevel;
    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";

            if (leftToRight)
            {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }

        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->left->left = new Node(12);
    root->left->right->left->right = new Node(13);
    root->left->right->right->left = new Node(9);
    root->left->right->right->right = new Node(10);

    zigZagTraversal(root);
    cout << endl;
    zigZagTraversal2(root);

    return 0;
}