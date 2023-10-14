#include <bits/stdc++.h>
using namespace std;

// Question: https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// TC: Insetion: O(Length of string) and Search: O(Length of string) and Deletion: O(Length of string)

// Deifference between Trie and Hashmap: Trie has better space optimizations
// In hashmap eeach word take its own space but in trie space is distributed through characters

// We can put TrieNode class outside of trie class also.
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal; // Important. Why need this? Explanation given in the book

    TrieNode(char ch)
    {
        this->data = ch;

        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;

        isTerminal = false;
    }
};

class Trie
{
    /*

    // We can put TrieNode class inside of trie class also

    class TrieNode
    {
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            this->data = ch;

            for (int i = 0; i < 26; i++)
                this->children[i] = NULL;

            isTerminal = false;
        }
    };
    */
    // private:
    void insertUtil(TrieNode *root, string word, int idx)
    {

        if (idx == word.length())
        {
            root->isTerminal = true;
            return;
        }

        if (root->children[word[idx] - 'A'])
            insertUtil(root->children[word[idx] - 'A'], word, idx + 1);
        else
        {
            root->children[word[idx] - 'A'] = new TrieNode(word[idx]);
            insertUtil(root->children[word[idx] - 'A'], word, idx + 1);
        }
    }

    bool searchUtil(TrieNode *root, string word, int idx)
    {
        if (idx == word.length())
        {
            // if (root->isTerminal)
            //     return true;
            // return false;

            return root->isTerminal;
        }

        if (root->children[word[idx] - 'A'])
            return searchUtil(root->children[word[idx] - 'A'], word, idx + 1);
        return false;
    }

    void printAllWordsUtil(TrieNode *root, string &temp)
    {
        if (!root)
            return;

        if (root->isTerminal)
            cout << temp << endl;

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                temp += root->children[i]->data;
                printAllWordsUtil(root->children[i], temp);
                temp.pop_back(); // required
            }
        }
    }

    void deleteWordUtil(TrieNode *root, string word, int idx)
    {
        if (idx == word.length())
        {
            root->isTerminal = false;
            return;
        }

        if (root->children[word[idx] - 'A'] == NULL)
            return;

        deleteWordUtil(root->children[word[idx] - 'A'], word, idx + 1);
    }

    ///////////////////////////////////////////////////////////////
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
        insertUtil(root, word, 0);
    }

    bool search(string word)
    {
        if (word.length() == 0)
            return false;
        return searchUtil(root, word, 0);
    }

    void printAllWords()
    {
        string temp = "";
        printAllWordsUtil(root, temp);
    }

    void deleteWord(string word)
    {
        // Search the word. Is found, convert the isTerminal of last character to false;
        deleteWordUtil(root, word, 0);
    }
};

int main()
{
    // Trie t1;
    // t1.insert("CART");
    // t1.insert("CAR");
    // // t1.insert("abcd"); // Error
    // cout << t1.search("ARM") << endl;
    // cout << t1.search("CAR") << endl;
    // cout << t1.search("CART") << endl;
    // cout << t1.search("CARTY") << endl;
    // cout << t1.search("CA") << endl;
    // // cout << t1.search("abcd") << endl; // Error

    Trie t2;

    t2.insert("ARM");
    t2.insert("DO");
    t2.insert("TIME");
    t2.insert("TIM");
    t2.insert("TIMBERLAKE");
    t2.insert("ARC");
    t2.insert("APP");
    // t2.insert("abcd"); // Error

    cout << "Before delete\n";
    t2.printAllWords();
    cout << "Search for TIM before delete is " << t2.search("TIM") << endl;

    t2.deleteWord("TIM");
    t2.deleteWord("TIMES");
    t2.deleteWord("DO");
    t2.deleteWord("DOG");

    cout << "After delete\n";
    t2.printAllWords();
    cout << "Search for TIM After delete is " << t2.search("TIM") << endl;

    cout << "Test" << endl;
    return 0;
}