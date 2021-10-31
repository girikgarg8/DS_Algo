#include <iostream>
using namespace std;
int numOfBalancedBT(int h,int dp[]){
    //Height here is node count
    if (dp[h]!=(-1)){
        return dp[h];
    }
    //Base Case
    if (h==0 || h==1){
        return 1;
    }
    //Recursive call
    int a=numOfBalancedBT(h-1,dp);
    int b=numOfBalancedBT(h-2,dp);
    return dp[h]=a*a+2*a*b;
}
int main(){
    int n;
    cin>>n;
    int dp[n+1];
    for (int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout << numOfBalancedBT(n,dp) <<endl;
    return 0;
}