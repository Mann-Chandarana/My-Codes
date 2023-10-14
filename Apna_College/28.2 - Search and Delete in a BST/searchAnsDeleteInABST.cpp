#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insertInBST(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    if (val < root->data)
        insertInBST(root->left, val);
    else
        insertInBST(root->right, val);
}

Node *searchInBST(Node *root, int key) // O(logN) base 2.
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (key < root->data)
        return searchInBST(root->left, key);
    return searchInBST(root->right, key);
}

Node *inOrderSucc(Node *root)
{
    Node *temp = root;
    while (temp != NULL and temp->left != NULL)
        temp = temp->left;

    return temp;
}

// Delete in BST:
Node *deleteInBST(Node *root, int key)
{
    if (key < root->data)
        root->left = deleteInBST(root->left, key);
    else if (key > root->data)
        root->right = deleteInBST(root->right, key);
    else
    {
        // Case 1 and 2, also included node being a leaf case.
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3.
        // Explanation written in the book.
        Node *temp = inOrderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root; // For getting the new root. Same if not delete and new if deleted.
}

void inOrderPrint(Node *root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main()
{
    Node *root = NULL;
    int arr[] = {10, 6, 4, 9, 8, 15, 12, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
        insertInBST(root, arr[i]);

    inOrderPrint(root);
    cout << endl;
    // if (searchInBST(root, 9) != NULL)
    //     cout << "Found" << endl;
    // else
    //     cout << "Cannot Find" << endl;
    // if (searchInBST(root,99) != NULL)
    //     cout << "Found" << endl;
    // else
    //     cout << "Cannot Find" << endl;
    root = deleteInBST(root, 15);
    inOrderPrint(root);
    cout << endl;

    return 0;
}