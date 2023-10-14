#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int d)
    {
        data = d;
        next = NULL;
        child = NULL;
    }
};

Node *push(Node *head, int val)
{
    if (head == NULL)
    {
        head = new Node(val);
        return head;
    }
    else
    {
        Node *newHead = new Node(val);
        newHead->child = head;
        return newHead;
    }
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        Node *downIt = temp;
        while (downIt)
        {
            cout << downIt->data << " ";
            downIt = downIt->child;
        }
        cout << endl;
        temp = temp->next;
    }
}

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node *ans = NULL;

    if (head1->data < head2->data)
    {
        ans = head1;
        ans->child = merge(head1->child, head2);
    }
    else
    {
        ans = head2;
        ans->child = merge(head1, head2->child);
    }

    ans->next = NULL;
    return ans;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *down = head;
    head->next = flattenLinkedList(head->next);

    Node *res = merge(down, head->next);

    return res;
}

int main()
{

    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        |    |	   |	 |
        V    V	   V	 V
        7    20    22    35
        |		   |	 |
        V		   V	 V
        8		   50    40
        |			     |
        V			     V
        30			     45
    */

    Node *head = NULL;

    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);

    head->next = push(head->next, 20);
    head->next = push(head->next, 10);

    head->next->next = push(head->next->next, 50);
    head->next->next = push(head->next->next, 22);
    head->next->next = push(head->next->next, 19);

    head->next->next->next = push(head->next->next->next, 45);
    head->next->next->next = push(head->next->next->next, 40);
    head->next->next->next = push(head->next->next->next, 35);
    head->next->next->next = push(head->next->next->next, 20);

    cout << "Original linked lis:\n";
    printLL(head);

    // Flatten the list
    head = flattenLinkedList(head);

    cout << "Flatten linked list:\n";
    printLL(head);

    return 0;
}
