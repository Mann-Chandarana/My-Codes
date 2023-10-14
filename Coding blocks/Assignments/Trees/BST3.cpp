//////////// Kth largest and smallest elements

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

void KthSmallest(Tree *root, int k)
{
    static int i = 0;
    if (root == NULL)
    {
        return;
    }
    KthSmallest(root->left, k);
    i += 1;
    if (i == k)
    {
        cout << root->data << endl;
    }
    KthSmallest(root->right, k);
}

void KthLargest(Tree *root, int k, int n)
{
    static int i = 0;
    if (root == NULL)
    {
        return;
    }
    KthLargest(root->left, k, n);
    i += 1;
    if (i == n - k + 1)
    {
        cout << root->data << endl;
    }
    KthLargest(root->right, k, n);
}

void sumOfLargest(Tree *&root)
{
    static int sum = 0;
    if (root == NULL)
    {
        return;
    }
    sumOfLargest(root->right);
    int temp = root->data;
    root->data = sum;
    sum += temp;
    sumOfLargest(root->left);
}

void preOrderTraversal(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    // int n, k;
    // cin >> n;
    // int *arr = new int[n];
    // Tree *root = NULL;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    //     root = insertInBst(root, arr[i]);
    // }
    // cin >> k;
    // KthSmallest(root, n - k + 1);

    // delete[] arr;

    Tree *root = NULL;
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        root = insertInBst(root, arr[i]);
    }
    sumOfLargest(root);
    cout << root->left->data << " => " << root->data << " <= " << root->right->data << endl;
    cout << "END => " << root->left->data << " <= END" << endl;
    cout << "END => " << root->right->data << " <= END" << endl;

    return 0;
}