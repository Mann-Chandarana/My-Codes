#include <bits/stdc++.h>
using namespace std;

void getArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void partition(int *arr, int start, int end, int pivotIdx)
{
    int i = start, j = end;

    while (i < pivotIdx and j > pivotIdx)
    {
        while (arr[i] <= arr[pivotIdx])
            i++;

        while (arr[j] > arr[pivotIdx])
            j--;
        if (i < pivotIdx and j > pivotIdx)
        {
            swap(arr[i++], arr[j--]);
        }
    }
}

void quickSort(int *arr, int start, int end)
{
    // Base condition
    if (start >= end)
        return;

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= arr[start])
            count++;
    }

    int pivotIdx = start + count;

    // Put pivot element to its right place.
    swap(arr[start], arr[pivotIdx]);
    // [.... <a .....][a][...... >a .....]
    partition(arr, start, end, pivotIdx);

    // Recursion call for the left part.
    quickSort(arr, start, pivotIdx - 1);
    // Recursion call for the right part.
    quickSort(arr, pivotIdx + 1, end);

    // algorithm given in notebook.
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    getArr(arr, n);
    printArr(arr, n);
    quickSort(arr, 0, n - 1);
    printArr(arr, n);

    return 0;
}

// LOVE BABBAR CODE:
/*
#include<iostream>
using namespace std;


int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenge
    int p = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right wala part sort karo
    quickSort(arr, p+1, e);

}

int main() {

    int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}
*/