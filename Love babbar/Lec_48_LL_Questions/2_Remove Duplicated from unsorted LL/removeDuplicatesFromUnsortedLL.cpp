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


///////// use unordered_map<Node*, int> count;
Node *removeDuplicates(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    unordered_map<int, int> count;

    Node *temp = head->next;
    Node *start = head;
    count[head->data] = 1;

    while (temp != NULL)
    {
        while (temp != NULL and count[temp->data] == 1)
        {
            temp = temp->next;
        }
        if(temp != NULL)
        {
            count[temp->data] = 1;
        }
        start->next = temp;
        start = temp;
        
        if (temp != NULL)
            temp = temp->next;
    }

    return head;
}

int main()
{

    Node *head = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        insertAtTail(head, temp);
    }

    printLL(head);

    removeDuplicates(head);

    printLL(head);

    return 0;
}