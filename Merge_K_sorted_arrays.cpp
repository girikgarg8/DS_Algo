#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <int> mergeKsortedArrays (vector <vector <int>> & kArrays,int k){
    vector <int> result;
    priority_queue <pair<int,pair<int,int>>,vector <pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
    for (int i = 0; i < kArrays.size(); i++)
    {
        minHeap.push({ kArrays[i][0], { i, 0 } }); 
    }
    while (minHeap.empty() == false) 
    { 
        pair<int, pair<int, int> > curr = minHeap.top(); 
        minHeap.pop(); 
  
        int i = curr.second.first; 
        int j = curr.second.second; 
    
        // Add the removed element to the output array.
        result.push_back(curr.first); 
  
        // If the next element of the extracted element exists, add it to the heap.
        if (j + 1 < kArrays[i].size())
        {
            minHeap.push({ kArrays[i][j + 1], { i, j + 1 } }); 
        }
    } 
     // Return the output array.
    return result; 
}
