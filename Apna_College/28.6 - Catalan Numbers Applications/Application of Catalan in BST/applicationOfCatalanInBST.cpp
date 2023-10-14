#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<Node *> constructTrees(int start, int end)
{
    vector<Node *> trees;

    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubTrees = constructTrees(start, i - 1); // Rule of BST, leftSt < rootNode < rightST.
        vector<Node *> rightSubTrees = constructTrees(i + 1, end);

        for (int j = 0; j < leftSubTrees.size(); j++)
        {
            Node *leftNode = leftSubTrees[j];
            for (int k = 0; k < rightSubTrees.size(); k++)
            {
                Node *rightNode = rightSubTrees[k];
                Node *rootNode = new Node(i);
                rootNode->left = leftNode;
                rootNode->right = rightNode;
                trees.push_back(rootNode);
            }
        }
    }

    return trees;
}

void preOrderPrint(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main()
{
    vector<Node *> totalTrees = constructTrees(1, 3);

    for (auto i : totalTrees)
    {
        preOrderPrint(i);
        cout << endl;
    }

    return 0;
}