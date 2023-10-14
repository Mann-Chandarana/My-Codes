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
        head = new Node(val);
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new Node(val);
    }
}

void printLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Node *head;
    Node *temp1 = head1, *temp2 = head2;
    if (head1->data <= head2->data)
    {
        head = head1;
        temp1 = temp1->next;
    }
    else
    {
        head = head2;
        temp2 = temp2->next;
    }
    Node *temp = head;

    while (temp1 and temp2)
    {
        if (temp1->data <= temp2->data)
        {
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    while (temp1)
    {
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    return head;
}

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

Node *findMid(Node *&head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

Node *mergeSort(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node *result = mergeUsingRecursion(left, right);

    return result;
}

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        insertAtTail(head, temp);
    }

    cout << "Before sorting:\n";
    printLL(head);

    head = mergeSort(head);

    cout << "After sorting:\n";
    printLL(head);

    return 0;
}