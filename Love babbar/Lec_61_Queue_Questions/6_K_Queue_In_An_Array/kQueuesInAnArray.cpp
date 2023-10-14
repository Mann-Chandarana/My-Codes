#include <bits/stdc++.h>
using namespace std;

class kQueue
{
    int n;
    int k;
    int *arr;
    int *next;
    int *front;
    int *rear;
    int freeSpot;

public:
    kQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        freeSpot = 0;

        arr = new int[n];

        next = new int[n];
        for (int i = 0; i < n; i++)
            next[i] = i + 1;
        next[n - 1] = -1;

        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
            front[i] = rear[i] = -1;
    }

    void enqueue(int data, int qn)
    {
        // Overflow
        if (freeSpot == -1)
        {
            cout << "Queue is already full" << endl;
            return;
        }

        // Find first free index
        int index = freeSpot;

        // Update freespot
        freeSpot = next[index];

        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // Link new element to the last element of that queue
            next[rear[qn - 1]] = index;
        }

        // Update next
        next[index] = -1;

        // Update rear
        rear[qn - 1] = index;

        // push element into array
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue is already empty" << endl;
            return -1;
        }

        // Find index
        int index = front[qn - 1];

        // Update (Move forward) front
        front[qn - 1] = next[index];

        // Make next of current spot a freespot
        next[index] = freeSpot;

        // Store current spot into freeSpot variable
        freeSpot = index;

        return arr[index];
    }

    int getFront(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty";
            return -1;
        }
        return arr[front[qn - 1]];
    }
};

int main()
{
    kQueue q(7, 3);

    // q.enqueue(10, 1);
    // q.enqueue(15, 1);
    // q.enqueue(20, 2);
    // q.enqueue(25, 1);
    // cout << q.getFront(2) << endl;
    // q.dequeue(1);
    // q.dequeue(1);
    // cout << q.getFront(1) << endl;

    q.enqueue(10, 1);
    q.enqueue(11, 2);
    q.enqueue(12, 1);
    q.enqueue(13, 2);
    q.enqueue(14, 2);
    q.enqueue(15, 1);
    q.enqueue(16, 1);
    q.enqueue(17, 1);

    return 0;
}