// #include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    /*
          1
         / \
        2   3
       / \
      4   5 
    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    return 0;
}