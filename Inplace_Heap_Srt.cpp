#include <iostream>
using namespace std;
void inplaceHeapSort(int pq[], int n)
{
    //build the heap in input array
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
                break;
            childIndex = parentIndex;
        }
    }
    while (n > 1)
    {
        swap(pq[0], pq[n - 1]);
        n--;
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < n)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < n && pq[rightChildIndex] < pq[minIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
            { //at its correct position
                break;
            }
            swap(pq[parentIndex], pq[minIndex]);
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}
int main()
{
    int arr[] = {5, 1, 2, 0, 8};
    int n = sizeof(arr) / sizeof(int);
    inplaceHeapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}