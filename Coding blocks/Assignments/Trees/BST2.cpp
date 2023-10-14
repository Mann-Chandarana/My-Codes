//////////////// Delete Nodes inBST

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

Tree *CreateBST(int *a, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Tree *root = new Tree(a[mid]);
    root->left = CreateBST(a, s, mid - 1);
    root->right = CreateBST(a, mid + 1, e);
    return root;
}

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
    Tree *root = NULL;

    while (n--)
    {
        cin >> data;
        root = insertInBst(root, data);
    }

    return root;
}


int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, n1;
        cin >> n;
        Tree *root = Build(n);
        cin >> n1;
        int del_Data;
        // while (n1--)
        // {
        //     cin >> del_Data;
        //     root = deleteInBST(root, del_Data);
        // }
        // preOrderTraversal(root);
        // cout << endl;
    }

    return 0;
}