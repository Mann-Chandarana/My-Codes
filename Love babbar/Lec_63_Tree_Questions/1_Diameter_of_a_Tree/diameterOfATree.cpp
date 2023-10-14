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

int height(Node *root)
{
    if (!root)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

pair<int, int> diameterUsingPairs(Node *root)
{
    // First of pair store the diameter and second of pair stores the height of that node (sub tree)

    if (!root)
        return make_pair(0, 0);

    pair<int, int> left = diameterUsingPairs(root->left);
    pair<int, int> right = diameterUsingPairs(root->right);

    int leftAns = left.first;
    int rightAns = right.first;

    int nodeAns = left.second + right.second + 1;

    pair<int, int> ans;

    ans.first = max(leftAns, max(rightAns, nodeAns));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int getDiameter(Node *root)
{
    // T.C.: O(N^2) S.C.: O(Height of the tree)
    /*
    if (!root)
        return 0;

    int op1 = getDiameter(root->left);
    int op2 = getDiameter(root->right);

    int op3 = height(root->left) + height(root->right) + 1;

    return max(op1, max(op2, op3));
    */

    // Using pair T.C.: O(N) S.C.: O(Height of the tree)
    return diameterUsingPairs(root).first;
}

int main()
{
    Node *root = new Node(2);

    root->left = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(3);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(3);

    root->right = new Node(6);
    root->right->right = new Node(6);
    root->right->right->right = new Node(6);
    root->right->right->right->left = new Node(6);
    root->right->right->right->right = new Node(6);
    root->right->right->right->left->right = new Node(6);

    cout << getDiameter(root) << endl;

    return 0;
}