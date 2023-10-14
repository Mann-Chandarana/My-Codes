#include <bits/stdc++.h>
using namespace std;

// We can print inorder traversal using Morris traversal in O(N) time and O(1) space.

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Read algorithm from the book

void morrisTraversal(Node *root)
{
    Node *curr = root;

    while (curr)
    {
        if (!curr->left)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != NULL and pred->right != curr)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = curr;
                cout << curr->data << " ";
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
}

void preOrderTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(7);

    root->right = new Node(3);
    root->right->right = new Node(6);

    cout << "In-order traversal using rec: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Morris traversal: ";
    morrisTraversal(root);
    cout << endl;

    return 0;
}