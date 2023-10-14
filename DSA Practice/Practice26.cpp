#include <iostream>
#include <queue>
using namespace std;
//////////////////////////////////////
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
//////////////////////////////////////
Node *Create_Node(int value)
{
    Node *n = new (Node);
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}
//////////////////////////////////////
void Inorder_Traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder_Traversal(root->left);
    cout << root->data << " ";
    Inorder_Traversal(root->right);
}
//////////////////////////////////////
void Sum_Replacement(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    Sum_Replacement(root->left);
    Sum_Replacement(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }

    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}
//////////////////////////////////////
void fattern_Tree(Node *root)
{
    if ((root == NULL) || (root->left == NULL) && (root->right == NULL))
    {
        return;
    }
    if (root->left != NULL)
    {
        fattern_Tree(root->left);
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;

        fattern_Tree(root->right);
    }
}
int main()
{
    Node *p = Create_Node(7);
    Node *p1 = Create_Node(6);
    Node *p2 = Create_Node(5);
    p->left = p1;
    p->right = p2;

    Node *p3 = Create_Node(4);
    Node *p4 = Create_Node(3);

    p1->left = p3;
    p1->right = p4;

    Node *p5 = Create_Node(2);
    Node *p6 = Create_Node(1);

    p2->left = p5;
    p2->right = p6;

    fattern_Tree(p);
    Inorder_Traversal(p);

    return 0;
}