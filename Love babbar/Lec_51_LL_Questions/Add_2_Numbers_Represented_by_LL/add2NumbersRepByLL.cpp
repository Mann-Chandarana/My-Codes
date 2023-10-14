#include <bits/stdc++.h>
using namespace std;

// Final optimized code is uploaded in GFG question. Link in lec51. 

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

int getNumFromLL(Node *&head)
{
    int ans = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        ans = ans * 10 + temp->data;
        temp = temp->next;
    }

    return ans;
}

int sumOfNumbersRepByLL(Node *&head1, Node *&head2)
{
    int num1 = getNumFromLL(head1);
    int num2 = getNumFromLL(head2);
    // cout << num1 << " " << num2 << endl;

    return num1 + num2;
}

void reverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

// Create a new linked list having integers from that addition
int getVal(Node *&node)
{
    if (node == NULL)
        return 0;

    return node->data;
}

Node *sumOf2LL(Node *head1, Node *head2)
{
    // head1 = 3 4 5
    // head2 = 4 6
    reverseLL(head1);
    reverseLL(head2);
    // head1 = 5 4 3
    // head2 = 6 4

    Node *temp1 = head1, *temp2 = head2;

    int carry = 0;
    Node *newHead = NULL; // We can use dummy node concept also. Node *newHead = new Node(-1), return newHead->next

    int dig = getVal(temp1) + getVal(temp2);
    carry = dig / 10;
    dig %= 10;
    newHead = new Node(dig);
    if (temp1)
        temp1 = temp1->next;
    if (temp2)
        temp2 = temp2->next;

    Node *temp = newHead;
    // while ((temp1 != NULL) and (temp2 != NULL))
    while ((temp1 != NULL) or (temp2 != NULL) or carry == 1)
    {
        int dig = getVal(temp1) + getVal(temp2) + carry;
        carry = dig / 10;
        dig %= 10;
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;

        // insertAtTail(newHead, dig);
        temp->next = new Node(dig);
        temp = temp->next;
    }
    // while (temp1 != NULL)
    // {
    //     int dig = getVal(temp1) + getVal(temp2) + carry;
    //     carry = dig / 10;
    //     dig %= 10;
    //     temp1 = temp1->next;

    //     // insertAtTail(newHead, dig);
    //     temp->next = new Node(dig);
    //     temp = temp->next;
    // }
    // while (temp2 != NULL)
    // {
    //     int dig = getVal(temp1) + getVal(temp2) + carry;
    //     carry = dig / 10;
    //     dig %= 10;
    //     temp2 = temp2->next;

    //     // insertAtTail(newHead, dig);
    //     temp->next = new Node(dig);
    //     temp = temp->next;
    // }

    // if (carry)
    // {
    //     temp->next = new Node(1);
    //     temp = temp->next;
    //     // insertAtTail(newHead, 1);
    // }

    reverseLL(newHead);

    return newHead;
}

int main()
{
    Node *head1 = NULL, *head2 = NULL;
    int n1, n2;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int temp;
        cin >> temp;
        insertAtTail(head1, temp);
    }

    cin >> n2;

    for (int i = 0; i < n2; i++)
    {
        int temp;
        cin >> temp;
        insertAtTail(head2, temp);
    }

    cout << "Answer stored in int: " << sumOfNumbersRepByLL(head1, head2) << endl;
    Node *newHead = sumOf2LL(head1, head2);

    cout << "Answer stored in a new linked list:\n";
    printLL(newHead);

    return 0;
}