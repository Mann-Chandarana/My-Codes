#include <bits/stdc++.h>
using namespace std;

// For 1 based indexing, left child is at 2*idx and right child is at (2*idx + 1) and parent is at idx/2
// For 0 based indexing, left child is at (2*idx + 1) and right child is at (2*idx + 2) and parent is at (idx - 1)/2

// This is the class of max heap and all the operations are implemented based on the characteristics of max heap.
class Heap
{
public:
    int *arr = new int[100];
    int idx;

    Heap()
    {
        arr[0] = -1;
        idx = 0;
    }
    // In max heap, arr[1] must be the greatest value in the entire array.

    // This insert is implemented considering max heap
    void insert(int data) // TC: O(log N)
    {
        if (idx == 99)
        {
            cout << "Heap is full" << endl;
            return;
        }

        arr[++idx] = data;
        int tempIdx = idx;

        while (tempIdx > 1)
        {
            if (arr[tempIdx] > arr[tempIdx / 2])
            {
                swap(arr[tempIdx], arr[tempIdx / 2]);
                tempIdx /= 2;
            }
            else
                break;
        }
    }

    // In Heaps deletion is done at root node, SO no argument is needed
    // This deletion is implemented considering max heap
    void deletion() // O(log N)
    // deleteFromHeap is a better function
    {
        if (idx == 0)
        {
            cout << "Heap is already empty" << endl;
            return;
        }
        if (idx == 1)
        {
            idx--;
            return;
        }

        arr[1] = arr[idx];
        idx--;
        int tempIdx = 1;

        while (tempIdx <= idx)
        {
            if (tempIdx * 2 > idx)
                return;

            int swapIdx;
            int leftIdx = tempIdx * 2;
            int rightIdx = tempIdx * 2 + 1;

            if ((tempIdx * 2 + 1) > idx and arr[tempIdx * 2] > arr[tempIdx])
                swapIdx = tempIdx * 2;

            else
            {
                if (arr[leftIdx] > arr[rightIdx])
                    swapIdx = leftIdx;
                else
                    swapIdx = rightIdx;

                if (arr[tempIdx] < arr[swapIdx])
                {
                    swap(arr[tempIdx], arr[swapIdx]);
                    tempIdx = swapIdx;
                }
                else
                    return;
            }
        }
    }

    void deleteFromHeap() // O(log N)
    {
        if (idx == 0)
        {
            cout << "Heap is already empty" << endl;
            return;
        }

        // Copy last node to root node
        arr[1] = arr[idx];
        // Decrease the size
        idx--;

        // Take the new node to its correct place
        int i = 1;
        while (i < idx)
        {
            int leftIdx = i * 2;
            int rightIdx = i * 2 + 1;

            if (leftIdx > idx) // meaning there is no child node
                return;

            if (rightIdx > idx) // Meaning there is only left child
            {
                if (arr[i] < arr[leftIdx])
                {
                    swap(arr[i], arr[leftIdx]);
                    i = leftIdx;
                }
                else
                    return;
            }
            else // Meaning there are both left and right children
            {
                int swapIdx;
                if (arr[leftIdx] > arr[rightIdx])
                    swapIdx = leftIdx;
                else
                    swapIdx = rightIdx;

                if (arr[i] < arr[swapIdx])
                {
                    swap(arr[i], arr[swapIdx]);
                    i = swapIdx;
                }
                else
                    return;
            }
        }
    }

    int getMax() // O(1)
    {
        if (idx == 0)
            return -1;

        return arr[1];
    }

    void printArray()
    {
        if (idx == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        for (int i = 1; i <= idx; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// heapifyByBabbar is a better function
void heapify(int *arr, int n, int idx)
{
    while (idx < n)
    {
        int leftIdx = idx * 2;
        int rightIdx = idx * 2 + 1;

        if (leftIdx > n)
            return;

        if (rightIdx > n)
        {
            if (arr[idx] < arr[leftIdx])
            {
                swap(arr[idx], arr[leftIdx]);
                idx = leftIdx;
            }
            else
                return;
        }
        else
        {
            int swapIdx;
            if (arr[leftIdx] > arr[rightIdx])
                swapIdx = leftIdx;
            else
                swapIdx = rightIdx;

            if (arr[idx] < arr[swapIdx])
            {
                swap(arr[idx], arr[swapIdx]);
                idx = swapIdx;
            }
            else
                return;
        }
    }
}

void heapifyByBabbar(int *arr, int n, int i)
{
    int idx = i;
    int leftIdx = i * 2;
    int rightIdx = i * 2 + 1;

    if (leftIdx <= n and arr[idx] < arr[leftIdx])
        idx = leftIdx;
    if (rightIdx <= n and arr[idx] < arr[rightIdx])
        idx = rightIdx;

    if (idx != i) // Whether the BT is already a heap or not
    {
        swap(arr[idx], arr[i]);
        heapify(arr, n, idx);
    }
}

void buildHeap(int *arr, int n) // TC: O(nlogn) SC: O(1)
{
    // Heapify function will convert the normal array to heap array.
    // We are considering max heap here.

    for (int i = n / 2; i > 0; i--)
    {
        // heapify(arr, n, i);
        heapifyByBabbar(arr, n, i);
    }
}

int main()
{
    // Insertion and deletion in heap
    /*
    Heap maxHeap;
    maxHeap.insert(40);
    cout << maxHeap.getMax() << endl;
    maxHeap.printArray();

    maxHeap.insert(30);
    cout << maxHeap.getMax() << endl;
    maxHeap.printArray();

    maxHeap.insert(55);
    cout << maxHeap.getMax() << endl;
    maxHeap.printArray();

    maxHeap.insert(60);
    maxHeap.insert(20);
    maxHeap.insert(50);
    maxHeap.insert(100);

    cout << maxHeap.getMax() << endl;
    maxHeap.printArray();

    cout << "Deletetion:\n";

    maxHeap.deletion();
    maxHeap.printArray();

    maxHeap.deletion();
    maxHeap.printArray();

    maxHeap.deletion();
    maxHeap.printArray();

    maxHeap.deletion();
    maxHeap.printArray();
    */

    // Deletion in heap using different deletion function
    /*
     Heap h;
     h.insert(50);
     h.insert(55);
     h.insert(53);
     h.insert(52);
     h.insert(54);

     h.printArray();

     // h.deleteFromHeap();
     // h.printArray();
     // h.deleteFromHeap();
     // h.printArray();

     h.deletion();
     h.printArray();
     h.deletion();
     h.printArray();

     // Both deletion and deleteFromHeap are same and correct
    */

    // heapify algorithm
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    arr[1] = -1;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    buildHeap(arr, n);

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}