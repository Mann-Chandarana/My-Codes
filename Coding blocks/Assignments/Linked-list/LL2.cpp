////// LL K-reverse

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

Node *reverseKlist(Node *&head, int k)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;
    int count = 0;

    if (head == NULL && head->next == NULL)
    {
        return head;
    }

    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (currptr != NULL)
    {
        head->next = reverseKlist(currptr, k);
    }
    return prevptr;
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
    int n, ele, k;
    cin >> n >> k;
    Node *Head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        insert_at_last(Head, ele);
    }
    Node *newHead = reverseKlist(Head, k);
    print_list(newHead);

    return 0;
}