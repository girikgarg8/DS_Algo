#include <bits/stdc++.h>
using namespace std;
int tsp(vector <vector<int>> mat,int setOfCities,int currCity,int n){
    //Base Case
    if (setOfCities==((1<<n)-1)){
        //return the cost from city to original city
        return mat[0][currCity];
    }
    int ans=INT_MAX;
    for (int choice=0;choice<n;choice++){
        if ((setOfCities&(1<<choice))==0){
            int subProblem=mat[currCity][choice]+tsp(mat,setOfCities|(1<<choice),choice,n);
            ans=min(ans,subProblem);
        }
    }
    return ans;
}
int main(){
    vector <vector <int> > mat={{0,20,42,25},{20,0,30,34},{42,30,0,10},{25,34,10,0}};
    int ans=tsp(mat,1,0,4);
    cout <<ans <<endl;
    return 0;
}