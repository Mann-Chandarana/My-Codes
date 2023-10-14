//////////////// Maxsum in bloodline
/////////////// LCA
/////////////// Kth sum path
/////////////// Kth Ansecstor
/////////////// Sum of Adjacent

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

void bloodline(Tree *root, int sum, int maxsum, int len, int maxlen)
{
    if (root == NULL)
    {
        if (len > maxlen)
        {
            len = maxlen;
            sum = maxsum;
        }
        else if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }

    sum = sum + root->data;

    bloodline(root->left, sum, maxsum, len + 1, maxlen);
    bloodline(root->right, sum, maxsum, len + 1, maxlen);
}

Tree *lca(Tree *root, int n1, int n2)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Tree *leftAns = lca(root->left, n1, n2);
    Tree *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return NULL;
}

Tree *Kthanscestor(Tree *root, int k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }
    Tree *leftAns = Kthanscestor(root->left, k, node);
    Tree *rightAns = Kthanscestor(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            //// Answer locking
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (rightAns != NULL && leftAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            //// Answer locking
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
}

void KThSum_Path(Tree *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    KThSum_Path(root->left, k, count, path);
    KThSum_Path(root->right, k, count, path);

    int size = path.size();
    int sum = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}

pair<int, int> Sum_of_Adjacent(Tree *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    //// first including current node
    //// second excluding current node
    pair<int, int> left = Sum_of_Adjacent(root->left);
    pair<int, int> right = Sum_of_Adjacent(root->right);

    pair<int, int> res;

    res.first = root->data + left.second + right.second;

    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int main()
{
    return 0;
}
