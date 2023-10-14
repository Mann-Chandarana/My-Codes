//////// Delete nodes

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
    ~Node()
    {
        if (next != NULL)
        {
            next == NULL;
        }
    }
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

// void delete_Nodes(Node *&Head)
// {
//     if (Head == NULL || Head->next == NULL)
//     {
//         return;
//     }
//     if (Head->data < Head->next->data)
//     {
//         Node *temp = Head;
//         Head = Head->next;
//         delete (temp);
//         delete_Nodes(Head);
//     }
//     else
//     {
//         if (Head->next != NULL)
//         {
//             delete_Nodes(Head->next);
//         }
//     }
// }

Node *delete_Nodes(Node *head, int &maxi)
{
    if (head == NULL)
    {
        return head;
    }
    head->next = delete_Nodes(head->next, maxi);
    if (head->data < maxi)
    {
        return head->next;
    }
    maxi = max(head->data, maxi);
    return head;
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
    int n, ele;
    cin >> n;
    Node *head = NULL;
    while (n--)
    {
        cin >> ele;
        insert_at_last(head, ele);
    }
    int maxi = INT_MIN;
    Node *newHead = delete_Nodes(head, maxi);
    print_list(newHead);

    return 0;
}