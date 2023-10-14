/// Morris traversal

#include <bits/stdc++.h>
using namespace std;

// We can print inorder traversal using Morris traversal in O(N) time and O(1) space.

///// Algorithm
/*
1) if left part exists then find inorder predesccor and if pred right does not exist create temporary link
2) else if left does not exists then print right
3) last step if pred right does not exists then make it null
*/

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

void morrisTraversal(Tree *root)
{
    Tree *curr = root;

    while (curr)
    {
        if (!curr->left)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Tree *pred = curr->left;
            while (pred->right != NULL and pred->right != curr)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

void flattern(Tree *root)
{
    Tree *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            Tree *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void inOrderTraversalRec(Tree *root)
{
    if (!root)
        return;

    inOrderTraversalRec(root->left);
    cout << root->data << " ";
    inOrderTraversalRec(root->right);
}

int main(int argc, char const *argv[])
{
    Tree *t;
    BuildFromlevelorder(t);
    inOrderTraversalRec(t);
    cout << endl;
    morrisTraversal(t);

    return 0;
}
