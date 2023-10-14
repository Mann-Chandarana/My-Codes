///////// Kth element from last

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node(){};
};

int length_of_list(Node *Head)
{
    Node *temp = Head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void print_list(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int Kthfromlast(Node *Head, int k)
{
    int len = length_of_list(Head);
    if (Head == NULL || k > len)
    {
        return 0;
    }
    int count = 0;

    Node *fast = Head;
    Node *slow = Head;

    while (count < k)
    {
        fast = fast->next;
        count++;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

void insert_at_last(Node *&Head, int data)
{
    Node *temp = new Node(data);
    if (Head == NULL)
    {
        Head = temp;
        Head->next = NULL;
        return;
    }
    Node *p = Head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
}

int main()
{
    int ele, k;
    Node *Head = NULL;
    cin >> ele;
    while (ele != -1)
    {
        if (ele != -1)
        {
            insert_at_last(Head, ele);
        }
        cin >> ele;
    }
    cin >> k;
    cout << Kthfromlast(Head, k) << endl;

    return 0;
}