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

// void buildFromlevelOrder(Tree *&root)
// {
//     queue<Tree *> q;
//     cin >> data;
//     root = new Tree(data);
//     q.push(root);

//     while (!q.empty())
//     {
//         Tree *temp = q.front();
//         q.pop();

//         cin >> data;
//         if (data != -1)
//         {
//             temp->left = new Tree(data);
//             q.push(temp->left);
//         }

//         cin >> data;
//         if (data != -1)
//         {
//             temp->right = new Tree(data);
//             q.push(temp->right);
//         }
//     }
// }

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

// Tree *BuildFromPre_In(int *in, int *pre, int s, int e)
// {
//     static int i = 0;
//     if (s > e)
//     {
//         return NULL;
//     }
//     Tree *root = new Tree(pre[i]);
//     int index = -1;

//     for (int j = s; s <= e; j++)
//     {
//         if (in[j] == pre[i])
//         {
//             index = j;
//             break;
//         }
//     }

//     i++;
//     root->left = BuildFromPre_In(in, pre, s, index - 1);
//     root->right = BuildFromPre_In(in, pre, index + 1, e);
//     return root;
// }

Tree *BuildFrom_Post_In(int *in, int *post, int s, int e)
{
    static int i = e;
    if (s > e)
    {
        return NULL;
    }
    cout << "Post" << post[i] << endl;
    Tree *root = new Tree(post[i]);
    int index = -1;

    for (int j = s; s <= e; j++)
    {
        if (in[j] == post[i])
        {
            index = j;
            break;
        }
    }

    i--;
    root->right = BuildFrom_Post_In(in, post, index + 1, e);
    root->left = BuildFrom_Post_In(in, post, s, index - 1);
    return root;
}

int main()
{
    int n, n1;
    cin >> n;
    int *post = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    cin >> n1;
    int *in = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> in[i];
    }
    Tree *root = BuildFrom_Post_In(in, post, 0, n - 1);
    PrintTree(root);

    delete[] post, in;
    return 0;
}