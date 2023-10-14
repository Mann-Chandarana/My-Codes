#include <iostream>
using namespace std;
//////////////////////////////
class Node
{
public:
    int data;
    Node *next;
};
//////////////////////////////
void display(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
///////////////////////////////
void insert_end(Node *&head, int value)
{

    Node *ptr;
    ptr = new (Node);
    ptr->data = value;
    if (head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        return;
    }

    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
///////////////////////////////
Node *RemoveDuplicates(Node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.

    Node *ptr = head, *temp = NULL, *tmp = NULL;

    while (ptr != NULL && ptr->next != NULL)
    {
        temp = ptr->next;
        // ptr->next = NULL;

        while (temp != NULL && ptr->data == temp->data)
        {
            tmp = temp;
            temp = temp->next;

            tmp->next = NULL;
            delete (tmp);
        }
        ptr->next = temp;
        ptr = temp;
    }

    return head;
}

int main()
{
    Node *Head = NULL;
    Node *newHead = new (Node);
    int n, element;

    cin >> n;
    while (n--)
    {
        cin >> element;
        insert_end(Head, element);
    }
    newHead = RemoveDuplicates(Head);
    display(newHead);

    return 0;
}