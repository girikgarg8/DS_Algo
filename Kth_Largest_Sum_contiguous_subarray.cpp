#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int getKthLargest_brute_force (vector <int> &arr,int k){
    int n=arr.size();
    vector <int> storeSum; //vector to store the sum of all possible subarrays
    int sum=0;
    for (int i=0;i<n;i++){
        int sum=0;
        for (int j=i;j<n;j++){
            sum=sum+arr[j];
            storeSum.push_back(sum);
        }
    }
    //sort storeSum in decreasing order
    sort(storeSum.begin(),storeSum.end(),greater<int>());
    return storeSum[k-1];
}
int getKthLargest_Optimised (vector <int> &arr,int k){
    int n=arr.size();
    priority_queue <int,vector<int>, greater<int> > minHeap;
    for (int i=0;i<n;i++){
        int sum=0;
        for (int j=i;j<n;j++){
            sum=sum+arr[j];
            if (minHeap.size()<k){
                minHeap.push(sum);
            }
            else{
                if (minHeap.top()<sum){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}
int main(){
    vector <int> a={20,-5,-1};
    int k=3;
    cout << getKthLargest_brute_force(a,k) << "\n";
    cout << getKthLargest_Optimised(a,k);
    return 0;
}