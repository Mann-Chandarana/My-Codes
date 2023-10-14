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

void inOrder(Node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int minVal(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }

    return root->data;
}

Node *deleteFromBST(Node *&root, int val)
{
    // Love babbar code
    /*
    if (!root)
        return NULL;

    if (root->data == val)
    {
        // 0 child
        if (!root->left and !root->right)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // Left child
        if (root->left and !root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Right child
        if (!root->left and root->right)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        if (root->left and root->right)
        {
            // Find predecessor
            // We can do this with finding successor also

            int succ = minVal(root->right);
            root->data = succ;
            root->right = deleteFromBST(root->right, succ);

            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
    */

    // Apna college code
    if (!root)
        return NULL;

    if (val > root->data)
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
    else if (val < root->data)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            int succ = minVal(root->right);
            root->data = succ;
            root->right = deleteFromBST(root->right, succ);
            return root;
        }
    }
}

int main()
{
    Node *root = NULL;

    int arr[] = {70, 60, 90, 50, 65, 40, 64, 67, 69, 30, 45};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
        insert(root, arr[i]);

    cout << "Before deleteion:\n";
    inOrder(root);
    cout << endl;

    root = deleteFromBST(root, 70);

    cout << "After deleteion:\n";
    inOrder(root);
    cout << endl;

    return 0;
}