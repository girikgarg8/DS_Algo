#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <climits>
using namespace std;
vector <int> maximum_bruteforce (vector <int> &arr,int n,int k){
    vector <int> ans;
    for (int i=0;i<=(n-k);i++){
        int maximum=INT_MIN;
        for (int j=i;j<i+k;j++){
            maximum=max(maximum,arr[j]);
        }
        ans.push_back(maximum);
    }
    return ans;
}
vector <int> maximum_set(vector <int> &arr,int n,int k){
    vector <int> ans;
    set <pair<int,int> > st;
    for (int i=0;i<k;i++){
        st.insert({arr[i],i});
    }
    ans.push_back((*st.rbegin()).first);
    for (int i=k;i<n;i++){
        int prev=i-k;
        st.erase({arr[prev],prev});
        st.insert({arr[i],i});
        ans.push_back((*st.rbegin()).first);
    }
    return ans;
}
vector <int> maximum_deque (vector <int> &arr,int n,int k){
    vector <int> ans;
    deque <int> q;
    for (int i=0;i<k;i++){
        while (!q.empty() && arr[q.back()]<arr[i]){
            q.pop_back();
        }
    q.push_back(i);
    }
    ans.push_back(arr[q.front()]);
    for (int i=k;i<n;i++){
        while (!q.empty() && q.front()<=i-k){ //deleting all elements which are not  a part of the sliding window now
            q.pop_front();
        }
        while (!q.empty() && arr[q.back()]<arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(arr[q.front()]);
    }
    return ans;
}
int main(){
    vector <int> v={1,2,3,1,4,5,2,3,6};
    int n=v.size();
    int k=3;
    vector <int> ans=maximum_bruteforce(v,n,k);
    vector <int> ans1=maximum_set(v,n,k);
    vector <int> ans2=maximum_deque(v,n,k);
    for (auto u:ans){
        cout << u << " ";
    }
    cout << "\n";
     for (auto u:ans1){
        cout << u << " ";
    }
    cout <<"\n";
     for (auto u:ans2){
        cout << u << " ";
    }
    return 0;
}