////////////// Insertion and deletion in BST
////////////// LCA in BST

#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;

    Tree(){};

    Tree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Tree *insertInBst(Tree *root, int data)
{
    if (root == NULL)
    {
        return new Tree(data);
    }
    if (data <= root->data)
    {
        root->left = insertInBst(root->left, data);
    }
    else
    {
        root->right = insertInBst(root->right, data);
    }
    return root;
}

Tree *Build(int n)
{
    int data;
    // cout << "Enter data for BST" << endl;
    cin >> data;
    n -= 1;
    Tree *root = NULL;

    while (n--)
    {
        root = insertInBst(root, data);
        // cout << "Enter data for BST" << endl;
        cin >> data;
    }

    return root;
}

Tree *deleteInBST(Tree *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (data < root->data)
    {
        root->left = deleteInBST(root->left, data);
        return root;
    }
    else if (data == root->data)
    {
        ////// 1) Node with zero children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        ////// 2) Node with One children

        if (root->left != NULL && root->right == NULL)
        {
            Tree *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Tree *temp = root->right;
            delete root;
            return temp;
        }

        ////// 3) Node with two children

        Tree *replace = root->right;
        while (replace->left != NULL)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteInBST(root->right, replace->data);
        return root;
    }
    else
    {
        root->right = deleteInBST(root->right, data);
        return root;
    }
}

int LCA(Tree *root, int P, int Q)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data < P && root->data < Q)
    {
        return LCA(root->right, P, Q);
    }
    if (root->data > P && root->data > Q)
    {
        return LCA(root->left, P, Q);
    }
    return root->data;
}

void InorderTraversal(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

int main()
{
    Tree *root;
    int n, P, Q;
    cin >> n;
    root = Build(n);
    cin >> P >> Q;
    cout << LCA(root, P, Q) << endl;

    return 0;
}