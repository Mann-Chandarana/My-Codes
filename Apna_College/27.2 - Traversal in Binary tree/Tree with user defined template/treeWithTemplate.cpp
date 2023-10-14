#include "bits/stdc++.h"
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

template <class T>
void inOrderPrint(Node<T> *root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main()
{
    Node<float> *root = new Node<float>(5.6);
    root->left = new Node<float>(6.7);
    root->right = new Node<float>(19.85);
    root->right->left = new Node<float>(56.23);

    inOrderPrint(root);

    return 0;
}