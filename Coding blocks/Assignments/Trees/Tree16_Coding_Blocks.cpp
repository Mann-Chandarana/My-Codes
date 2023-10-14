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

void sumOfLargest(Tree *&root)
{
    static int sum = 0;
    if (root == NULL)
    {
        return;
    }
    sumOfLargest(root->right);
    sum += root->data;
    root->data = sum;
    sumOfLargest(root->left);
}

void levelOrderTraversal(Tree *root)
{
    queue<Tree *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void PreOrderTraversal(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
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
    }
    root = CreateBST(arr, 0, n - 1);
    sumOfLargest(root);
    PreOrderTraversal(root);

    delete[] arr;
    return 0;
}
