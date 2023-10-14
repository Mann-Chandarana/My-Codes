///////////// Reverse a linked list

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

Node *reverse_List(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }
    Node *newHead = reverse_List(Head->next);
    Head->next->next = Head;
    Head->next = NULL;

    return newHead;
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
    int n, ele;
    cin >> n;
    Node *head = NULL;
    while (n--)
    {
        cin >> ele;
        insert_at_last(head, ele);
    }
    Node *newHead = reverse_List(head);
    print_list(newHead);

    return 0;
}