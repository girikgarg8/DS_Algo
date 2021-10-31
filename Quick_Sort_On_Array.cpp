#include <iostream>
using namespace std;
int Partition(int arr[],int s,int e){
    int pivot=arr[e];
    int j=0;
    int i=-1;
    for (int j=s;j<=e;j++){
       if (arr[j]<pivot){
           i++;
           swap(arr[i],arr[j]);
       } 
    }
    swap(arr[i+1],arr[e]);
    int newPivotPosition=i+1;
    return newPivotPosition;
}
void QuickSort(int arr[],int s,int e){
    if (s>=e){
        return ;
    }
    int x=Partition(arr,s,e);
    QuickSort(arr,s,x-1);
    QuickSort(arr,x+1,e);
}
int main(){
    int arr[]={10,80,50,60,70};
    int n=sizeof(arr)/sizeof(int);
    QuickSort(arr,0,n-1);
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}