/////////// Digital dicitionary

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> Children;
    bool Terminal;

    Node(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            Children[i] = NULL;
        }
        Terminal = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    void Insert(Node *root, string word)
    {
        if (word.length() == 0)
        {
            root->Terminal = true;
            return;
        }
        int index = word[0] - 'a';
        Node *Child;
        if (root->Children[index] != NULL)
        {
            Child = root->Children[index];
        }
        else
        {
            Child = new Node(word[0]);
            root->Children[index] = Child;
        }
        Insert(Child, word.substr(1));
    }

    void InsertUtil(string word)
    {
        Insert(root, word);
    }

    bool search(Node *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }
        int index = word[0] - 'a';
        Node *Child;
        if (root->Children[index] != NULL)
        {
            Child = root->Children[index];
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
            if (root->Children[i])
            {
                str.push_back(i + 'a');
                Print_Trie(root->Children[i], str);
                str.pop_back();
            }
        }
    }

    void Print_Related_Trie(Node *root, string str)
    {
        if (root->Terminal)
        {
            cout << str << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->Children[i])
            {
                str.push_back(i + 'a');
                Print_Trie(root->Children[i], str);
                str.pop_back();
            }
        }
    }

    void PrintRelatedUtil(string word)
    {
        string answer = word;
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (temp->Children[index])
            {
                temp = temp->Children[index];
            }
        }

        Print_Related_Trie(temp, answer);
    }

    void PrintUtil()
    {
        string str = "";
        Print_Trie(root, str);
    }

    bool searchUtil(string word)
    {
        return search(root, word);
    }

    bool isEmpty(Node *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->Children[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Trie *root = new Trie();
    string str;
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        root->InsertUtil(str);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if (!root->searchUtil(str))
        {
            cout << "No suggestions" << endl;
            root->InsertUtil(str);
            continue;
        }
        root->PrintRelatedUtil(str);
    }

    return 0;
}
