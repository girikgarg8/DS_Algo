#include <iostream>
#include <climits>
using namespace std;
int minNumForSqaures(int n,int dp[]){
    for (int i=1;i<=n;i++){
        if (sqrt(i)==(float)sqrt(i)){
            dp[i]=1;
        }
        else{
            int ans=n;
            for (int j=1;j*j<=sqrt(i);j++){
                ans=min(ans,1+dp[i-j*j]);
            }
            dp[i]=ans;
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int *dp=new int[n+1];
    cout << minNumForSqaures(n,dp);
    return 0;
}