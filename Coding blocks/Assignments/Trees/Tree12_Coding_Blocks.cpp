///////////// No Sibling

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

int SumofNodes(Tree *root)
{
    static int sum = 0;
    if (root == NULL)
    {
        return 0;
    }
    sum += root->data;
    SumofNodes(root->left);
    SumofNodes(root->right);
    return sum;
}

void print_leaf_Node(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    print_leaf_Node(root->left);
    print_leaf_Node(root->right);
}

bool isIdentical(Tree *root1, Tree *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    if (left && right)
    {
        return true;
    }
    return false;
}
pair<int, bool> isHeightBalancedOptimised(Tree *root)
{
    pair<int, bool> p;
    if (root == NULL)
    {
        p = make_pair(0, true);
        return p;
    }
    pair<int, bool> left = isHeightBalancedOptimised(root->left);
    pair<int, bool> right = isHeightBalancedOptimised(root->right);

    p.first = max(left.first, right.first) + 1;
    int diff = abs(left.second - right.second);
    if (diff <= 1 && right.second && left.second)
    {
        p.second = true;
    }
    else
    {
        p.second = false;
    }
    return p;
}

//////// Taken from internet
void NoSibling(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left && !root->right)
    {
        cout << root->left->data << " ";
        return NoSibling(root->left);
    }
    else if (root->right && !root->left)
    {
        cout << root->right->data << " ";
        return NoSibling(root->right);
    }
    NoSibling(root->left);
    NoSibling(root->right);
}

Tree *remove_leaf(Tree *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = remove_leaf(root->left);
    root->right = remove_leaf(root->right);
    return root;
}

void PrintTree(Tree *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left)
    {
        cout << root->left->data << " => ";
    }
    else
    {
        cout << "END => ";
    }
    cout << root->data;
    if (root->right)
    {
        cout << " <= " << root->right->data;
    }
    else
    {
        cout << " <= END";
    }
    cout << endl;

    PrintTree(root->left);
    PrintTree(root->right);
}

int main()
{
    Tree *root;
    

    return 0;
}