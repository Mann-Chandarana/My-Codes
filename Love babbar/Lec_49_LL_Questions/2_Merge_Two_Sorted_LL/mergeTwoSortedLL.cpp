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
    if (head == NULL)
    {
        head = new Node(val);
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
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

// Made a new LL
Node *mergeTwoSorted(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *temp1 = head1, *temp2 = head2;
    Node *newHead = NULL;
    if (temp1->data <= temp2->data)
    {
        newHead = temp1;
        temp1 = temp1->next;
    }
    else
    {
        newHead = temp2;
        temp2 = temp2->next;
    }

    Node *temp = newHead;

    while ((temp1 != NULL) and (temp2 != NULL))
    {
        if (temp1->data < temp2->data)
        {
            temp->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp2 = temp2->next;
        }

        temp = temp->next;
    }

    while (temp1 != NULL)
    {
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }

    return newHead;
}

///////// Using recurssion
Node *mergeUsingRecursion(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node *ans = NULL;

    if (head1->data <= head2->data)
    {
        ans = head1;
        ans->next = mergeUsingRecursion(head1->next, head2);
    }
    else
    {
        ans = head2;
        head2->next = mergeUsingRecursion(head1, head2->next);
    }

    return ans;
}

Node *solve(Node *first, Node *second)
{
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;

    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

// Merge in linked list 1
Node *mergeTwoSortedInLL1(Node *&head1, Node *&head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        return solve(head1, head2);
    }
    else
    {
        return solve(head2, head1);
    }
}

int main()
{
    Node *head1 = NULL, *head2 = NULL;

    int n1, n2;
    cout << "Insert the length of first Linked List: ";
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int temp;
        cin >> temp;
        insertAtTail(head1, temp);
    }

    cout << "Insert the length of first Linked List: ";
    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        int temp;
        cin >> temp;
        insertAtTail(head2, temp);
    }

    // printLL(head1);
    // printLL(head2);

    // Node *newHead = mergeTwoSorted(head1, head2);
    // printLL(newHead);

    // Node *newHead1 = mergeTwoSortedInLL1(head1, head2);
    // printLL(newHead1);

    Node *newHead2 = mergeUsingRecursion(head1, head2);
    printLL(newHead2);

    cout << "MAin end ";
    return 0;
}