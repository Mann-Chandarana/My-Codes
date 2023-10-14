///////////// ZigZag traversal

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

void zigZagTraversal(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Tree *> q;
    q.push(root);
    bool leftToright = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        cout << "Size is " << size << endl;

        for (int i = 0; i < size; i++)
        {
            Tree *temp = q.front();
            q.pop();

            int index = leftToright ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        leftToright = !leftToright;
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    Tree *root;
    BuildFromlevelorder(root);
    // levelOrderTraversal(root);
    zigZagTraversal(root);
    return 0;
}
