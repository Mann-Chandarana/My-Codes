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
int size(Node *Head)
{
    Node *temp = Head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
bool compare(Node *head, Node *head1)
{
    int s1 = size(head);
    int s2 = size(head1);
    int count = 0;
    Node *temp = head;
    Node *temp1 = head1;
    if (s1 == s2)
    {
        while (temp != NULL)
        {
            temp = temp->next;
            temp1 = temp1->next;
            if (temp->data != temp1->data)
            {
                break;
            }
            count++;
        }
        if (count == s1)
        {
            return 1;
        }
    }
    return 0;
}
///////////////////////////////
void printAtgivenIndex(Node *head, int index)
{
    Node *temp = head;
    int count = 0;
    while (count != index)
    {
        temp = temp->next;
        count++;
    }
    cout << temp->data << endl;
}
///////////////////////////////
int main()
{
    Node *Head = NULL;
    int n, element;
    int i, index;
    cin >> n;
    cin >> i;
    index = n - i - 1;
    while (n--)
    {
        cin >> element;
        insert_end(Head, element);
    }
    //display(Head);
    printAtgivenIndex(Head, index);

    // Node *Head1 = NULL;
    // int n1, element1;
    // cin >> n1;
    // while (n1--)
    // {
    //     cin >> element1;
    //     insert_end(Head1, element1);
    // }
    // cout << compare(Head, Head1) << endl;

    return 0;
}