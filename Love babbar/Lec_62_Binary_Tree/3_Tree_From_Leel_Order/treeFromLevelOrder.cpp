#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *treeFromLevelOrder(int *arr, int n)
{
    if (n == 0)
        return NULL;
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int it = 1;

    while (it < n)
    {
        q.front()->left = new Node(arr[it++]);
        q.push(q.front()->left);
        if (it >= n)
            break;
        q.front()->right = new Node(arr[it++]);
        q.push(q.front()->right);

        q.pop();
    }

    return root;
}

void preOrderTraverse(Node *&root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void reverseLevelOrder(Node *&root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    stack<Node *> st;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (!q.front())
        {
            st.push(NULL);
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            st.push(q.front());
            if (q.front()->right)
                q.push(q.front()->right);
            if (q.front()->left)
                q.push(q.front()->left);
            q.pop();
        }
    }
    if (st.top() == NULL)
        st.pop();

    while (!st.empty())
    {
        if (st.top() == NULL)
            cout << endl;
        else
        {
            cout << st.top()->data << " ";
        }
        st.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = treeFromLevelOrder(arr, n);
    
    cout << "Pre order:\n";
    preOrderTraverse(root);
    cout << endl;

    cout << "ReverseLevel Order:\n";
    reverseLevelOrder(root);

    return 0;
}