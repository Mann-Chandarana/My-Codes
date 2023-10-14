#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T val)
    {
        this->key = key;
        value = val;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <class T>
class Hashtable
{
    int hashfn(string key)
    {
        int idx = 0;
        int p = 1;
        for (int i = 0; i < key.length(); i++)
        {
            idx += (key[i] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

    void rehash()
    {
        Node<T> **oldtable = table;
        int oldTable_size = table_size;
        table_size = 2 * oldTable_size;
        table = new Node<T> *[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
        current_size = 0;

        for (int i = 0; i < oldTable_size; i++)
        {
            Node<T> *temp = oldtable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            if (oldtable[i] != NULL)
            {
                delete oldtable[i];
            }
        }
        delete[] oldtable;
    }

public:
    int current_size;
    int table_size;
    Node<T> **table;

    Hashtable(int ts = 7)
    {
        table_size = ts;
        current_size = 0;
        table = new Node<T> *[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, int value)
    {
        int idx = hashfn(key);
        Node<T> *n = new Node<T>(key, value);
        /////////// Insert at the head of the linked
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        float load_Factor = current_size / (1.0 * table_size);
        if (load_Factor > 0.7)
        {
            rehash();
        }
    }

    T *serach(string key)
    {
        int idx = hashfn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &(temp->value);
            }
            temp = temp->next;
        }
        return NULL;
    }

    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout << "Bucket " << i << "->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T &operator[](string key)
    {
        T *f = serach(key);
        if (f == NULL)
        {
            T garbage;
            insert(key, garbage);
            f = serach(key);
        }
        return *f;
    }
};