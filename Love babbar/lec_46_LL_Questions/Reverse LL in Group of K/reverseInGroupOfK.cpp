#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(Node *&head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *reverseInGroupOfK(Node *&head, int k)
{
    int i = 0;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward;

    if (head == NULL or head->next == NULL)
        return head;

    while (i < k and curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }

    // if (curr != NULL)
    {
        head->next = reverseInGroupOfK(curr, k);
    }

    return prev;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 100);
    insertAtTail(head, 110);
    insertAtTail(head, 120);
    insertAtTail(head, 130);
    insertAtTail(head, 140);
    insertAtTail(head, 150);
    insertAtTail(head, 160);
    insertAtTail(head, 170);
    insertAtTail(head, 180);
    insertAtTail(head, 190);

    printLL(head);

    int k;
    cout << "Insert K: ";
    cin >> k;

    Node *newHead = reverseInGroupOfK(head, k);

    printLL(newHead);

    return 0;
}