//////////// Diameter of a tree
/////////// Diameter using optimised approach
/////////// Two binary tree are identical
/////////// is SUm

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

void buildFromlevelOrder(Tree *&root)
{
    queue<Tree *> q;
    cout << "Enter data for root Node" << endl;
    int data;
    cin >> data;
    root = new Tree(data);
    q.push(root);

    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();

        cout << "Enter data on left of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new Tree(data);
            q.push(temp->left);
        }

        cout << "Enter data on right of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->right = new Tree(data);
            q.push(temp->right);
        }
    }
}

int height(Tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height, right_height) + 1;
}

bool isIdentical(Tree *r1, Tree *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool is_left = isIdentical(r1->left, r2->left);
    bool is_right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (is_left && is_right && value)
    {
        return true;
    }
    return false;
}

int diameter(Tree *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = height(root->left) + height(root->right) + 1;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}

pair<bool, int> isSum(Tree *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> left = isSum(root->left);
    pair<bool, int> right = isSum(root->right);

    pair<bool, int> ans;
    bool data = root->data == left.second + right.second;

    if (data && left.first && right.first)
    {
        ans.first = true;
        ans.second = left.second + right.second + root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

pair<int, int> diameter_opti(Tree *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left_sub = diameter_opti(root->left);
    pair<int, int> right_sub = diameter_opti(root->right);

    int op1 = left_sub.first;                         ////// Diameter of left subtree
    int op2 = right_sub.first;                        ////// Diameter of right subtree
    int op3 = left_sub.second + right_sub.second + 1; ///// height

    pair<int, int> ans;

    ans.first = max(op1, max(op2, op3));
    ans.second = max(left_sub.second, right_sub.second) + 1;
    return ans;
}

int main()
{
    Tree *t;
    buildFromlevelOrder(t);
    pair<int, int> p = isSum(t);
    cout << p.first << endl;

    return 0;
}