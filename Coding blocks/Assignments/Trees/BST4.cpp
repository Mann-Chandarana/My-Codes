/////////////////// Replace with largest sum

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
void PrintTree(Tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left)
    {
        cout << root->left->data << " => ";
    }
    else
    {
        cout << "END => ";
    }
    cout << root->data;
    if (root->right)
    {
        cout << " <= " << root->right->data;
    }
    else
    {
        cout << " <= END";
    }
    cout << endl;

    PrintTree(root->left);
    PrintTree(root->right);
}

int main()
{
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
    PrintTree(root);

    return 0;
}