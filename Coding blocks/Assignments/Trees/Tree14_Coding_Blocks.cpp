///////////// Root to leaf

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

Tree *buildTree(Tree *&root)
{
    int data;
    cin >> data;
    root = new Tree(data);
    string val;
    cin >> val;
    if (val == "true")
    {
        root->left = buildTree(root->left);
    }
    cin >> val;
    if (val == "true")
    {
        root->right = buildTree(root->right);
    }
    return root;
}

//// there optimised code in above file
void sumPath(Tree *root, int k, vector<int> &ans)
{
    static int sum = 0;
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    sum += root->data;
    if (sum == k)
    {
        for (auto ele : ans)
        {
            cout << ele << " ";
        }
        return;
    }
    sumPath(root->left, k,ans);
    sumPath(root->right, k,ans);
    sum -= root->data;
    ans.pop_back();
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

int main()
{
    Tree *root;
    buildTree(root);
    int k;
    cin >> k;
    vector<int> ans;
    sumPath(root, k,ans);

    return 0;
}
