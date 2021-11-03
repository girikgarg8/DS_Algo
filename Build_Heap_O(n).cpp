#include <iostream> //Building max heap
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;
    if (leftChild<n && arr[leftChild]>arr[largest]){
        largest=leftChild;
    }
    if (rightChild<n && arr[rightChild]>arr[largest]){
        largest=rightChild;
    }
    if (largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest); //heapifying the levels below the given level
    }
}
void buildHeap (int arr[],int n){
    int startIndex=(n/2)-1;
    for (int i=startIndex;i>=0;i--){
        heapify(arr,n,i);
    }
}
int main(){
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
  
    int n = sizeof(arr) / sizeof(arr[0]);
  
    buildHeap(arr, n);
  for (auto u:arr){
      cout << u << " ";
  }
  return 0;
}