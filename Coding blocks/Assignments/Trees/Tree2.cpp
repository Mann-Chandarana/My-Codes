/////////// Count leaf Node
/////////// Height of a tree
/////////// isBalanced Tree;
/////////// isBalanced BFS;

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

bool isBalanced(Tree *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool l = 0, r = 0;
    l = isBalanced(root->left);
    r = isBalanced(root->right);

    int left_height = height(root->left);
    int right_height = height(root->right);

    if (abs(left_height - right_height >= 2))
    {
        return false;
    }

    return l && r;
}

pair<bool, int> isOpti_Balance(Tree *root)
{
    pair<bool, int> p;
    if (root == NULL)
    {
        p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> p_left = isOpti_Balance(root->left);
    pair<bool, int> p_right = isOpti_Balance(root->right);

    p.second = max(p_left.second, p_right.second) + 1;

    if (abs(p_left.second - p_right.second <= 1) && p_left.first && p_right.first)
    {
        p.first = true;
    }
    else
    {
        p.first = false;
    }
    return p;
}

int count_Leaf(Tree *root)
{
    static int count = 0;
    if (root == NULL)
    {
        return count;
    }
    count_Leaf(root->left);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    count_Leaf(root->right);
}

int main()
{
    Tree *t;
    buildFromlevelOrder(t);

    pair<bool, int> p = isOpti_Balance(t);
    cout << p.first << endl;

    return 0;
}
