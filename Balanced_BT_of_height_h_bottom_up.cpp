#include <iostream>
using namespace std;
int numOfBalancedBT(int h){
    int dp[h+1];
    dp[0]=1;
    dp[1]=1;
    for (int i=2;i<=h;i++){
        dp[i]=dp[i-1]*dp[i-1]+2*dp[i-1]*dp[i-2];
    }
    return dp[h];
}
int main(){
    int n;
    cin>>n;
    cout << numOfBalancedBT(n) <<endl;
    return 0;
}
