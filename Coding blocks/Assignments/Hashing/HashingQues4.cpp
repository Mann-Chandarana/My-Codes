////////// Top and bottom view of a tree

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
    // cout << "Enter data for root Node" << endl;
    int data;
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

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

void TopView(Tree *root, int dis, vector<pair<int, int>> &ans)
{
    static unordered_map<int, int> mp1;
    if (root == NULL)
    {
        return;
    }
    if (mp1[dis] == 0)
    {
        ans.push_back({root->data, dis});
        mp1[dis]++;
    }
    TopView(root->left, dis - 1, ans);
    TopView(root->right, dis + 1, ans);
}

void BottomView(Tree *root, int dis, vector<pair<int, int>> &ans)
{
    static unordered_map<int, int> mp1;
    if (root == NULL)
    {
        return;
    }
    BottomView(root->right, dis + 1, ans);
    BottomView(root->left, dis - 1, ans);
    if (mp1[dis] == 0)
    {
        ans.push_back({root->data, dis});
        mp1[dis]++;
    }
}

int main()
{
    Tree *root;
    buildFromlevelOrder(root);
    vector<pair<int, int>> ans;
    BottomView(root, 0, ans);
    sort(ans.begin(), ans.end(), compare);
    for (auto p : ans)
    {
        cout << p.first << " ";
    }

    return 0;
}