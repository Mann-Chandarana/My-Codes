/////////////// Build tree from preorder and inorder
////////////// Print right view

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

Tree *BuildFromPre_In(int *in, int *pre, int s, int e)
{
    static int i = 0;
    if (s > e)
    {
        return NULL;
    }
    Tree *root = new Tree(pre[i]);
    int index = -1;

    for (int j = s; s <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = BuildFromPre_In(in, pre, s, index - 1);
    root->right = BuildFromPre_In(in, pre, index + 1, e);
    return root;
}

void printRightView(Tree *root, int level, int maxlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (maxlevel < level)
    {
        cout << root->data << " ";
        maxlevel = level;
    }
    printRightView(root->right, level + 1, maxlevel);
    printRightView(root->left, level + 1, maxlevel);
}

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

int main()
{
    Tree *root;
    // int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    // int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    // int n = sizeof(pre) / sizeof(int);
    // root = BuildFromPre_In(in, pre, 0, n - 1);
    // levelOrderTraversal(root);

    BuildFromlevelorder(root);
    printRightView(root, 0, -1);

    return 0;
}