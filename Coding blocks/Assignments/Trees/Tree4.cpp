/////////////// Count node
/////////////// Sum of node
////////////// Build tree from array
////////////// Shortest distance between two node

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

void iNOrdertraversaL(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    iNOrdertraversaL(root->left);
    cout << root->data << " ";
    iNOrdertraversaL(root->right);
}

int countNode(Tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_count = countNode(root->left);
    int right_count = countNode(root->right);

    return left_count + right_count + 1;
}

int sum_of_Nodes(Tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int leftSum = sum_of_Nodes(root->left);
    int rightSum = sum_of_Nodes(root->right);

    int temp = root->data;

    return temp + leftSum + rightSum;
}

Tree *buildTree(int *arr, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Tree *root = new Tree(arr[mid]);
    root->left = buildTree(arr, s, mid - 1);
    root->right = buildTree(arr, mid + 1, e);

    return root;
}

int search(Tree *root, int a, int level)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == a)
    {
        return level;
    }
    int leftAns = search(root->left, a, level + 1);
    if (leftAns != -1)
    {
        return leftAns;
    }
    return search(root->right, a, level + 1);
}


Tree *LCA(Tree *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a || root->data == b)
    {
        return root;
    }

    Tree *leftAns = LCA(root->left, a, b);
    Tree *rightAns = LCA(root->right, a, b);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }

    if (leftAns != NULL)
    {
        return leftAns;
    }
    return rightAns;
}


int shortest_Dis(Tree *root, int a, int b)
{
    if (root == NULL)
    {
        return 0;
    }
    Tree *lca = LCA(root, a, b);
    int first = search(lca, a, 0);
    int second = search(lca, b, 0);

    if (first != -1 && second != -1)
    {
        return first + second;
    }
    return -1;
}

int main()
{
    Tree *root;
    // BuildFromlevelorder(root);
    // iNOrdertraversaL(root);
    // cout << sum_of_Nodes(root) << endl;

    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // root = buildTree(arr, 0, 7);
    // levelOrderTraversal(root);

    BuildFromlevelorder(root);
    levelOrderTraversal(root);
    cout << shortest_Dis(root, 8, 13) << endl;

    return 0;
}