#include <bits/stdc++.h>
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

void preOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (!q.front())
        {
            cout << endl;
            q.pop();
            if (!q.empty()) // Sperator for each level
                q.push(NULL);
            // continue;
        }
        else
        {
            cout << q.front()->data << " ";
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);

            q.pop();
        }
    }
    cout << endl;
}

void reverseLevelOrderTraversal(Node *&root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    stack<Node *> st;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (!q.front())
        {
            st.push(q.front());
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            st.push(q.front());

            // Important step, Push right child first and then left child
            if (q.front()->right)
                q.push(q.front()->right);
            if (q.front()->left)
                q.push(q.front()->left);
            q.pop();
        }
    }
    if (!st.empty())
        st.pop();

    while (!st.empty())
    {
        if (!st.top())
            cout << endl;

        else
        {
            cout << st.top()->data << " ";
        }
        st.pop();
    }
}

int noOfLeafNodes(Node *root)
{
    if(!root)
        return 0;
    if ((!root->left) and (!root->right))
        return 1;

    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}

int main()
{
    // Node *head = new Node(3);
    // head->left = new Node(1);
    // head->right = new Node(2);
    /*
            3 (Root)
           / \
          1   2
     (left)   (right)
    */

    Node *root = new Node(1);
    root->left = new Node(7);
    root->left->left = new Node(13);
    root->left->left->right = new Node(12);
    root->right = new Node(4);
    root->right->left = new Node(16);
    root->right->right = new Node(-5);
    root->right->right->left = new Node(17);

    // cout << "Pre order traversal:\n";
    // preOrderTraversal(root);
    // cout << endl;

    // cout << "In order traversal:\n";
    // inOrderTraversal(root);
    // cout << endl;

    // cout << "Post order traversal:\n";
    // postOrderTraversal(root);
    // cout << endl;

    // cout << "Level order traversal:\n";
    // levelOrderTraversal(root);
    // cout << "Reverse level order traversal:\n";
    // reverseLevelOrderTraversal(root);

    cout << "No. of Leaf Nodes: " << noOfLeafNodes(root) << endl;

    cout << "Main end" << endl;
    return 0;
}