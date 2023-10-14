////////// Burn tree in a minute

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

Tree *createParentMapping(Tree *root, int target, map<Tree *, Tree *> &nodeToparent)
{
    Tree *res = NULL;

    queue<Tree *> q;
    q.push(root);
    nodeToparent[root] = NULL;

    while (!q.empty())
    {
        Tree *front = q.front();
        q.pop();

        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToparent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToparent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

void burnTree(Tree *root, map<Tree *, Tree *> &nodeToparent)
{
    map<Tree *, bool> visited;
    queue<Tree *> q;

    q.push(root);
    visited[root] = true;
    int ans = 0;
    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        { /////// Processing neighbouring nodes
            Tree *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if (nodeToparent[front] && !visited[nodeToparent[front]])
            {
                flag = 1;
                q.push(nodeToparent[front]);
                visited[nodeToparent[front]] = 1;
            }
        }

        if (flag == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int minTime(Tree *root, int target)
{
    // algo
    //  Step 1: create nodeToparent mapping
    //  Step 2: find target node
    //  Step 3: burn the tree in min time

    int ans = 0;
    map<Tree *, Tree *> nodeToparent;
    Tree *targetNode = createParentMapping(root, target, nodeToparent);
    burnTree(targetNode, nodeToparent);
}

int main()
{
    return 0;
}
