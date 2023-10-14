//////////// Maximum sum path from node to node

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

class Pair
{
public:
    int maxsum;
    int branchsum;

    Pair()
    {
        maxsum = 0;
        branchsum = 0;
    }
};
void BuildFromlevelorder(Tree *&root)
{
    queue<Tree *> q;
    int data;
    cout << "Enter data for the node" << endl;
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

Pair maxSumPath(Tree *root)
{
    Pair p;
    if (root == NULL)
    {
        return p;
    }

    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    /// Construct two values
    int op1 = root->data;
    int op2 = root->data + left.branchsum;
    int op3 = root->data + right.branchsum;
    int op4 = left.branchsum + right.branchsum + root->data;

    int current_ans_through = max(op1, max(op2, max(op3, op4)));

    ////// Branch sum of current root

    p.branchsum = max(left.branchsum, max(right.branchsum, 0)) + root->data;
    p.maxsum = max(left.maxsum, max(right.maxsum, current_ans_through));
    return p;
}