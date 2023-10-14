#include <bits/stdc++.h>
using namespace std;

// Ideal way is to use only tail.
// We can access tail and head both using only tail.

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
};

void printCirLL(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << endl;
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

void insertAtHead(Node *&head, int val)
{
    if (head == NULL)
    {
        head = new Node(val);
        head->next = head;
    }
    else
    {
        Node *temp = new Node(val);
        Node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
    }
    else
    {
        Node *temp = new Node(val);

        Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
    }
}

void insertAtK(Node *&head, int pos, int val)
{
    if (pos == 1)
        insertAtHead(head, val);
    else if (head == NULL)
        return;
    else
    {
        int cnt = 1;
        Node *temp = head;

        while (cnt < pos - 1)
        {
            cnt++;
            if (temp->next == head)
                break;
            temp = temp->next;
        }
        Node *nodeToInsert = new Node(val);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
}

void deletion(Node *&head, int pos)
{
    if (head == NULL or pos <= 0)
        return;

    if (pos == 1)
    {
        if (head->next == head)
        {
            head = NULL;
        }
        else
        {
            Node *temp = head;
            Node *del = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = del->next;
            head = temp->next;
            del->next = NULL;
            delete del;
        }
        return;
    }
    else
    {
        int cnt = 1;
        Node *temp = head;
        while (cnt < pos - 1)
        {
            if (temp->next->next == head)
                break;
            temp = temp->next;
            cnt++;
        }
        Node *del = temp->next;
        temp->next = del->next;
        del->next = NULL;
        delete del;
    }
}

void deleteByValue(Node *&head, int val)
{
    if (head == NULL)
        return;

    if (head->next == head)
    {
        if (head->data == val)
        {
            head = NULL;
            return;
        }
        else
            return;
    }
    else
    {
        Node *temp = head;
        do
        {
            temp = temp->next;
            if (temp == head)
                return;
        } while (temp->next->data != val);

        Node *del = temp->next;
        temp->next = del->next;
        if(del == head)
            head = head->next;
        del->next = NULL;
        delete del;
    }
}

int main()
{

    Node *head = NULL;
    // printCirLL(head);
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtTail(head, 70);

    insertAtHead(head, 0);

    printCirLL(head);

    cout << "Insert the position for inserting a value: ";
    int k;
    cin >> k;
    cout << "Insert the value: ";
    int val;
    cin >> val;
    insertAtK(head, k, val);

    printCirLL(head);
    cout << head->data << endl;

    int pos;
    cout << "Insert the position for deleting that node: ";
    cin >> pos;
    deletion(head, pos);

    printCirLL(head);

    cout << "Insert the value for deleting that node: ";
    int valToDelete;
    cin >> valToDelete;
    deleteByValue(head, valToDelete);

    printCirLL(head);

    cout << "\n\nMain end...\n";
    return 0;
}