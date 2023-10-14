//////////// Tries implementation

#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////
class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool Terminal;

    Node(char data)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        this->data = data;
        Terminal = false;
    }
};
/////////////////////////////////////////////////////////
class Trie
{
    Node *root;

    void insert(Node *root, string word)
    {
        if (word.length() == 0)
        {
            root->Terminal = true;
            return;
        }
        int index = word[0] - 'A';
        Node *Child;
        if (root->children[index] != NULL)
        {
            Child = root->children[index];
        }
        else
        {
            Child = new Node(word[0]);
            root->children[index] = Child;
            // cout << root->children[index]->data << endl;
        }

        insert(Child, word.substr(1));
    }

    bool search(Node *root, string word)
    {
        if (word.length() == 0)
        {
            return root->Terminal;
        }
        int index = word[0] - 'A';
        Node *Child;
        if (root->children[index] != NULL)
        {
            Child = root->children[index];
        }
        else
        {
            return false;
        }
        return search(Child, word.substr(1));
    }

    void Print_Trie(Node *root, string str)
    {
        if (root->Terminal)
        {
            cout << str << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                str.push_back(i + 'A');
                Print_Trie(root->children[i], str);
                str.pop_back();
            }
        }
    }

    bool isEmpty(Node *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                return false;
            }
        }
        return true;
    }

    Node *remove(Node *root, string str, int depth = 0)
    {
        if (depth == str.size())
        {
            if (root->Terminal)
            {
                root->Terminal = false;
            }
            if (isEmpty(root))
            {
                delete (root);
                root = NULL;
            }
            return root;
        }

        int index = str[depth] - 'A';
        root->children[index] = remove(root->children[index], str, depth + 1);

        if (isEmpty(root) && root->Terminal == false)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }

public:
    Trie()
    {
        root = new Node('\0');
    }

    void insertUtil(string word)
    {
        insert(root, word);
    }

    bool searchUtil(string word)
    {
        return search(root, word);
    }
    void printUtil()
    {
        string str = "";
        Print_Trie(root, str);
    }

    void removeUtil(string word)
    {
        this->root = remove(root, word);
    }
};
/////////////////////////////////////////////////////////
int main()
{
    Trie *root = new Trie();

    string arr[6] = {"NO", "NONE", "MANN", "ALONE", "LONELY", "LOSER"};

    for (int i = 0; i < 6; i++)
    {
        root->insertUtil(arr[i]);
    }
    // cout << root->root->data << endl;
    cout << root->searchUtil("MANN") << endl;
    root->printUtil();
    root->removeUtil("MANN");
    cout << "Printing after deleting" << endl;
    root->printUtil();

    return 0;
}