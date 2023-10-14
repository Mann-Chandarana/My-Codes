//////// Creating tree
//////// InOrder traversal
//////// PreOrder traversal
//////// PostOrder traversal
///////  levelOrder Traversal
/////// creating tree using level order traversal

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

Tree *buildTree(Tree *root)
{
    cout << "Enter data :" << endl;
    int data;
    cin >> data;
    root = new Tree(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inOrderTraversal(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void PreOrderTraversal(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}

void PostOrderTraversal(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    cout << root->data << " ";
}

///// 4) - Predecessor

void Predecessor(Tree *root)
{
    Tree *temp = root->left;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    cout << temp->data << endl;
}

///// 5) - Successor

void Successor(Tree *root)
{
    Tree *temp = root->right;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    cout << temp->data << endl;
}

///// 6) - Count left node 

int count_Leaf_Node(Tree *root)
{
    static int count = 0;
    if (root == NULL)
    {
        return count;
    }
    count_Leaf_Node(root->left);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    count_Leaf_Node(root->right);
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

int main()
{
    Tree *t;
    // t = buildTree(t);
    // cout << "Inorder" << endl;
    // inOrderTraversal(t);
    // cout << "Preorder" << endl;
    // PreOrderTraversal(t);
    // cout << "Postorder" << endl;
    // PostOrderTraversal(t);
    // cout << "Level Order Traversal" << endl;
    // levelOrderTraversal(t);
    buildFromlevelOrder(t);
    cout << endl;
    cout << "Inorder traversal of tree is " << endl;
    inOrderTraversal(t);
    cout << endl;
    cout << "Preorder traversal of tree is " << endl;
    PreOrderTraversal(t);
    cout << endl;
    cout << "Postorder traversal of tree is " << endl;
    PostOrderTraversal(t);
    cout << endl;
    cout << "Predecessor of a root node is " << endl;
    Predecessor(t);
    cout << "Successor of a root node is " << endl;
    Successor(t);
    cout << "Total number of leaf node in a tree are " << count_Leaf_Node(t) << endl;

    return 0;
}