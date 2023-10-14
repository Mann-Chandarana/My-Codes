#include <bits/stdc++.h>
using namespace std;

// Insertion and deletion are written in different manner than in previous code

// Question: https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isTerminal = false;
    }
};

class Trie
{
    void insertUtil(TrieNode *root, string word)
    {
        cout << "Test" << endl;
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a';
        if (root->children[idx] == NULL)
            root->children[idx] = new TrieNode(word[0]);

        insertUtil(root->children[idx], word.substr(1));
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (root == NULL)
            return false;

        if (word.length() == 0)
            return root->isTerminal;

        int idx = word[0] - 'a';
        return searchUtil(root->children[word[0] - 'a'], word.substr(1));
    }

    void removeUtil(TrieNode *root, string word)
    {
        if (root == NULL)
            return;

        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        removeUtil(root->children[word[0] - 'a'], word.substr(1));
    }

public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string word)
    {
        if (word.length() == 0)
            return;
        insertUtil(root, word);
    }

    bool search(string word)
    {
        if (word.length() == 0)
            return false;
        return searchUtil(root, word);
    }

    void remove(string word)
    {
        removeUtil(root, word);
    }
};

string lca(TrieNode *root)
{
    if (!root)
        return "";

    string s = "";
    int check = 0;
    //     char ch;
    int idx;
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i])
        {
            check++;
            idx = i;
        }
    }

    if (check == 0 or check > 1)
        return s;

    s.push_back(root->children[idx]->data);

    return s + lca(root->children[idx]);
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Using trie
    // step 1: insert all string into TRIE.

    Trie *t;

    for (int i = 0; i < arr.size(); i++)
    {
        string word = arr[i];
        t->insert(word);
    }

    string ans = "";

    // return "";

    return lca(t->root);
}

//////////////// Without using trie

string longest(vector<string> &arr, int n)
{
    string ans = "";
    // for traversing all characters of first  string

    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[i][0];

        bool match = true;

        // for comparing ch with rest of the string
        for (int j = 1; j < n; j++)
        {
            // not match

            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }

        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{
    /*
    Trie t1;

    t1.insert("run");
    t1.insert("running");
    t1.insert("arm");
    t1.insert("armour");
    t1.insert("do");
    t1.insert("time");
    t1.insert("tim");

    cout << t1.search("run") << endl;
    cout << t1.search("running") << endl;
    cout << t1.search("runnings") << endl;
    cout << t1.search("tim") << endl;

    t1.remove("time");

    cout << t1.search("time") << endl;
    cout << t1.search("tim") << endl;
    */

    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Trie *t = new Trie;

    for (int i = 0; i < arr.size(); i++)
    {
        string word = arr[i];
        t->insert(word);
    }

    string ans = "";

    cout << ans << endl;
    ans = lca(t->root);
    cout << ans << endl;

    cout << "End test\n";
    return 0;
}