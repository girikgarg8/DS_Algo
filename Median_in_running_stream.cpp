#include <iostream>
#include <queue>
using namespace std;
vector <int> findMedian (vector <int> &arr,int n){
   //To store the medians
	vector<int> medians;
	priority_queue <int> max;
    priority_queue <int, vector<int>, greater<int>> min;
    for(int i=0 ;i<n ;i++)
    {
        if(i==0)
        { max.push(arr[i]); }
         else
        {
            if(arr[i] < max.top())
                max.push(arr[i]);
            else 
                min.push(arr[i]);
         }
          if(int(max.size()-min.size() )> 1)
        {  int x=max.top();
           max.pop();
           min.push(x);
        }
        else if(int(min.size()-max.size()) > 1)
        {  int x=min.top();
           min.pop();
           max.push(x);
        }
         int c=max.size()+min.size();  //count
        
        //checking size of list to find median
        if(c%2==0)
            cout<<(max.top()+min.top())/2<<endl;
             else
        {
            if(max.size()>min.size())
                cout<<max.top()<<endl;
            else
                cout<<min.top()<<endl;
        }
    }
    return medians;
}
vector <int> findMedian_InsertionSort(vector <int> &arr,int n){
    //To store the incoming elements
	vector<int> store;
	
	// To store the medians
	vector<int> medians;
    	for(int i = 0; i < n; i++){
		
		// Insert the new element in the store vector 
		store.push_back(arr[i]);
		
		// shift it at its sorted position in store
		int j = 0;
		
		while(j < i){
			
			if(store[j] <= arr[i]){
				j++;	
			}
			else{
				break;
			}
			
		}
		
		// Shifting all the elements greater than the current element to the right 
		
		int k = i-1;
		
		while(k >= j){
			
			store[k+1] = store[k];
			k--;
			
		}
		
		// Inserting the current element at its sorted position
		store[j] = arr[i];
			
		int median;
		// Even number of elements are read, (Note - 0 based indexing is used)
		if((i+1)%2==0){
			
			// Average of middle two values
			median = (store[i/2] + store[(i+1)/2])/2;
				
		}
		// odd number of elements are read
		else{
			
			// The middle value of the sorted arrangement of the elements read so far
			median = store[i/2];
			
		}
		
		medians.push_back(median);
				
	}
	
	return medians;
}
int main(){
    vector <int> arr={7,2,8,3,1,5};
    int n=sizeof(arr)/sizeof(int);
    vector <int> ans=findMedian(arr,n);
    vector <int> ans1=findMedian_InsertionSort(arr,n);
    for (auto u:ans){
        cout << u << " ";
    }
    for (auto u:ans1){
        cout << u << " "; 
    }
}