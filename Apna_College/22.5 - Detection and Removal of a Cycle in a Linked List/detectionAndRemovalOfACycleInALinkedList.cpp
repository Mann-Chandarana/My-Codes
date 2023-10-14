#include <iostream>
using namespace std;

// Floyd's algorithm (Also called as Hare and tortoise algorithm).
// Important for interviews.

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void createCycle(node *&head, int pos)
{
    node *temp = head;
    node *jointNode; // To create a cycle at that node.
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            jointNode = temp;
        }

        count++;
        temp = temp->next;
    }
    temp->next = jointNode;
}

bool detectCycle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while(slow->next != fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
    
}

void displayLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    displayLinkedList(head);
    cout << detectCycle(head) << endl;
    createCycle(head, 3);
    // displayLinkedList(head); // Will run for infinte time as there is no end node in the list (Cyclic list).
    cout << detectCycle(head) << endl;
    removeCycle(head);
    cout << detectCycle(head) << endl;
    displayLinkedList(head);
    return 0;
}