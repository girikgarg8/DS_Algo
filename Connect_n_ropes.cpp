#include <iostream>
#include <queue>
using namespace std;
int minCost(int arr[],int n){
    priority_queue <int,vector<int>,greater<int> > pq;
    for (int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int ans=0;
    while (pq.size()>1){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        ans+=first;
        ans+=second;
        pq.push(first+second);
    }
    return ans;
}
int main(){
    int arr[]={4,3,2,6};
    int n=sizeof(arr)/sizeof(int);
    cout << minCost(arr,n) <<endl;
    return 0;
}