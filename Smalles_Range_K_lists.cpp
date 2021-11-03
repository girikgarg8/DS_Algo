#include <bits/stdc++.h>
using namespace std;
vector <int> smallestRange (vector <vector <int> > &nums){
    vector <pair<int,int> > allLists;
    for (int i=0;i<nums.size();i++){
        for (int j:nums[i]){
            allLists.push_back({j,i});
        }
    }
    sort (allLists.begin(),allLists.end()); //sorting is required as we have to find the interval
    int minimumLength=INT_MAX;
    int totalIDs=nums.size();
    unordered_map <int,int> mp;
    int totalIDinSubarray=0;
    int j=0;
    vector <int> ans;
    for (int i=0;i<allLists.size();i++){
        mp[allLists[i].second]++;
        if (mp[allLists[i].second]==1) totalIDinSubarray++;
        if (totalIDinSubarray==totalIDs){
            if (allLists[i].first-allLists[j].first+1<minimumLength){
                minimumLength=allLists[i].first-allLists[j].first+1;
                ans={allLists[j].first,allLists[i].first};
            }
        } 
        if (totalIDinSubarray==totalIDs){
            while (totalIDinSubarray==totalIDs){
                if (mp[allLists[j].second]>1) mp[allLists[j].second]--,j++;
                else break;
            }
        if (allLists[i].first-allLists[j].first+1<minimumLength){
            minimumLength=allLists[i].first-allLists[j].first+1;
            ans={allLists[j].first,allLists[i].first};
        }
    }   
}
return ans;
}
vector <int> smallestRange_optimised(vector <vector <int> > &a,int k,int n){
    vector <int> answer;
    int maximum=INT_MIN;
    int minimum=INT_MAX;
    priority_queue <pair<int,pair<int,int> >, vector <pair<int,pair<int,int>> > ,greater <pair<int,pair<int,int>>>> pq;
     // Insert the first element of each list in Min heap
     for (int i=0;i<k;i++){
         pq.push({a[i][0],{i,0}});
         maximum=max(maximum,a[i][0]);
         minimum=min(minimum,a[i][0]);
     }
    // Initialize the answer using current min and max
    int ans = maximum -minimum + 1;
    while (true){
        // Remove the minimum element from Min heap
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int row = p.second.first;
        int col = p.second.second;
        minimum = p.first;
        int len=maximum-minimum+1;
        //Update the variable ans with new range
        ans=min(ans,len);
        col++;
        if (col==n){
            break;
        }
        pq.push({a[row][col],{row,col}});
        maximum=max(maximum,a[row][col]);
    }
    answer={minimum,maximum};
    return answer;
}
int main(){
    vector <int> v1={4,10,15,24};
    vector <int> v2={0,9,12,20};
    vector <int> v3={5,18,22,30};
    vector <vector <int> > v={v1,v2,v3};
    vector <int> u=smallestRange(v);
    for (auto x:u){
        cout << x << " ";
    }
    cout <<endl;
    vector <int> k=smallestRange_optimised(v,3,4);
    for (auto x:k){
        cout << x << " ";
    }
    return 0;
}