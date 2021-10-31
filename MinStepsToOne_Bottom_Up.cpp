#include <iostream>
using namespace std;
int MinStepsToOne(int n,int dp[]){
    dp[1]=0;
    for (int i=2;i<=n;i++){
        if (i%2==0 && i%3==0)
        dp[i]=1+min(dp[i-1],min(dp[i/2],dp[i/3]));
        else if (i%2==0 && i%3!=0)
        dp[i]=1+min(dp[i-1],dp[i/2]);
        else if (i%3==0 && i%2!=0)
        dp[i]=1+min(dp[i-1],dp[i/3]);
        else dp[i]=1+dp[i-1];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int *dp=new int[n+1];
    cout << MinStepsToOne(n,dp);
    return 0;
}