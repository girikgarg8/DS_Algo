#include <bits/stdc++.h>
#include <cmath>
using namespace std;
void tugofwar(int arr[],int n,int i,int sum1,int sum2,vector <int> set1,vector <int>set2,int &diff,bool res[]){
    if (i==n){
        if (set1.size()==(n+1)/2){
            if (abs(sum1-sum2)<diff){
                diff=abs(sum1-sum2);
                for (int i=0;i<n;i++)
                    res[i]=false;
                for (int i=0;i<set1.size();i++)
                    res[set1[i]]=true;
            }
        }
        return ;
    }
    
    set1.push_back(i); //include in first set
    tugofwar(arr,n,i+1,sum1+arr[i],sum2,set1,set2,diff,res);
    set1.pop_back(); //backtrack

    set2.push_back(i); //include in second set
    tugofwar(arr,n,i+1,sum1,sum2+arr[i],set1,set2,diff,res);
    set2.pop_back(); //backtrack
}
int main(){
    int arr[]={23,45,-34,12,0,98,-99,4,189,-1,4};
    int n=sizeof(arr)/sizeof(int);
    vector <int> set1, set2;
    bool res[n]; //to indicate whether a given element is present in set 1 or set 2
    int diff=INT_MAX; //differnece between sum of the two subsets
    tugofwar(arr,n,0,0,0,set1,set2,diff,res);
    cout << "Set1 " <<endl;
    for (int i=0;i<n;i++){
        if (res[i]==true){
            cout << arr[i] << " ";
        }
    }
    cout <<endl;
    cout << "Set 2" <<endl;
    for (int i=0;i<n;i++){
        if (res[i]==false){
            cout << arr[i] << " ";
        }
    }
    cout << "Minimum difference is " << diff <<endl;
    return 0;
}