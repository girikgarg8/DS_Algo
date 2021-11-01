#include <iostream>
#include <queue>
using namespace std;
int main(){
    int arr[]={8,5,12,10,0,1,6,9};
    int n=sizeof(arr)/sizeof(int);
    priority_queue<int> pq;
    int k=4;
    for (int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for (int i=k;i<n;i++){
        if (arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while (!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}