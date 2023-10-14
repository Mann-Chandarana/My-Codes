#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    delete temp;
}

void insertAtTail(Node *&head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        temp = temp->next;
        delete temp;
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
        temp->prev = p;

        p = p->next->next;
        delete p;

        temp = temp->next;
        delete temp;
    }
}

void deleteAtPos(Node *&head, int k)
{
    if (head == NULL)
        return;
    if (k == 1)
    {
        Node *del = head;
        head = head->next;

        delete del;
    }
    else
    {
        int cnt = 1;
        Node *temp = head;

        while (cnt < k - 1)
        {
            if (temp->next->next == NULL)
            {
                break;
            }

            cnt++;
            temp = temp->next;
        }
        if (temp->next->next == NULL)
        {
            Node *del = temp->next;
            temp->next = temp->next->next;
            // temp->next->prev = temp;
            delete del;
        }
        else
        {
            Node *del = temp->next;
            temp->next->next->prev = temp;
            temp->next = temp->next->next;

            del->next = NULL;
            del->prev = NULL;
            delete del;
        }
    }
}

void deleteWithValue(Node *&head, int val)
{
    if (head == NULL)
        return;

    if (head->data == val)
    {
        Node *del = head;
        head = head->next;

        del->next = NULL;
        delete del;

        return;
    }

    Node *temp = head;
    while (temp->next != NULL and temp->next->data != val)
    {
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        if (temp->next->next == NULL) // Second last ele
        {
            Node *del = temp->next;
            temp->next = NULL;

            del->prev = NULL;
            delete del;
        }
        else
        {
            Node *del = temp->next;
            del->next->prev = temp;
            temp->next = del->next;

            del->next = NULL;
            del->prev = NULL;
            delete del;
        }
    }
}

int main()
{
    Node *head = new Node(110);
    insertAtTail(head, 120);
    insertAtTail(head, 130);
    insertAtTail(head, 140);
    insertAtTail(head, 150);
    insertAtTail(head, 160);
    insertAtTail(head, 170);
    insertAtTail(head, 180);
    insertAtTail(head, 190);

    print(head);

    // cout << "Insert the position: ";
    // int k;
    // cin >> k;
    // deleteAtPos(head, k);

    cout << "Insert the value you want to delete: ";
    int val;
    cin >> val;
    deleteWithValue(head, val);

    print(head);

    cout << "\n\nMain end..\n\n";
    return 0;
}