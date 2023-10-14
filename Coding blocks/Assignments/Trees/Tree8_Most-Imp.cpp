/////////// MostIMP --- Vertical order traversal - Anuj Bhaiya
//////////// Boundary Traversal
/////////// Top view
/////////// Bottom view
/////////// left view
/////////// right view

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
    // cout << "Enter data for the node" << endl;
    cin >> data;
    root = new Tree(data);
    q.push(root);

    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();

        // cout << "Enter data on left of " << temp->data << endl;
        cin >> data;
        if (data != -1)
        {
            temp->left = new Tree(data);
            q.push(temp->left);
        }

        // cout << "Enter data on right of " << temp->data << endl;
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

void traverseLeft(Tree *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(Tree *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Tree *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // wapas aagye
    ans.push_back(root->data);
}

vector<int> boundary(Tree *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // left part print/store
    traverseLeft(root->left, ans);

    // traverse Leaf Nodes

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}

void TopView(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    map<int, int> topNode;

    queue<pair<Tree *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Tree *, int> temp = q.front();
        q.pop();

        Tree *frontNode = temp.first;
        int hd = temp.second;

        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->left, hd + 1));
        }
    }
    for (auto i : topNode)
    {
        cout << i.second << " ";
    }
}

void BottomView(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    map<int, int> topNode;

    queue<pair<Tree *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Tree *, int> temp = q.front();
        q.pop();

        Tree *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->left, hd + 1));
        }
    }
    for (auto i : topNode)
    {
        cout << i.second << " ";
    }
}

void rightView(Tree *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    rightView(root->right, level + 1, ans);
    rightView(root->left, level + 1, ans);
}
void leftView(Tree *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
}


void verticalOrderTraversal(Tree *root)
{
    map<int, vector<int>> nodes;
    queue<pair<Tree *, int>> q;
    if (root == NULL)
    {
        return;
    }
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Tree *, int> p = q.front();
        q.pop();

        nodes[p.second].push_back(p.first->data);
        // if (!nodes[p.first])
        // {
        //     nodes[p.first].push_back(p.first->data);
        // }
        // else
        // {
        //     vector<int> ans;
        //     ans.push_back(p.first->data);
        //     nodes[p.first] = ans;
        // }

        if (p.first->left != NULL)
        {
            q.push(make_pair(p.first->left, p.second - 1));
        }
        if (p.first->right != NULL)
        {
            q.push(make_pair(p.first->right, p.second + 1));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    Tree *root;
    BuildFromlevelorder(root);
    // vector<int> ans;
    // rightView(root, 0, ans);
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // ans.clear();
    // leftView(root, 0, ans);
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    // levelOrderTraversal(root);
    // cout << endl;
    verticalOrderTraversal(root);

    return 0;
}
