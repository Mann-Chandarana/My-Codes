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

Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *fast = head, *slow = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{

    Node *head = NULL;
    insertAtTail(head, 110);
    insertAtTail(head, 120);
    insertAtTail(head, 130);
    insertAtTail(head, 140);
    insertAtTail(head, 150);
    insertAtTail(head, 160);
    insertAtTail(head, 170);
    // insertAtTail(head, 180);
    // insertAtTail(head, 190);

    Node *middleNode = findMiddle(head);
    cout << middleNode->data << endl;

    return 0;
}