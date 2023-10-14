#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

pair<bool, int> sumTreeCheck(Node *root)
{
    if (!root)
        return make_pair(true, 0);

    if (!root->left and !root->right)
        return make_pair(true, root->data);

    pair<bool, int> left = sumTreeCheck(root->left);
    pair<bool, int> right = sumTreeCheck(root->right);

    pair<bool, int> ans;
    ans.first = left.first and right.first;
    if ((left.second + right.second) != root->data)
        ans.first = false;

    ans.second = left.second + right.second + root->data;

    return ans;
}

bool isSumTree(Node *root)
{
    return sumTreeCheck(root).first;
}

int main()
{
    Node *root = new Node(26);
    root->left = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(4);
    root->right = new Node(3);
    root->right->right = new Node(3);

    if (isSumTree(root))
        cout << "Sum tree" << endl;
    else
        cout << "Not a sum tree" << endl;

    return 0;
}