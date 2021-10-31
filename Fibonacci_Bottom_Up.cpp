#include <iostream>
using namespace std;
int fib_helper(int n,int dp[]){
    dp[0]=0;
    dp[1]=1;
    for (int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fib(int n){
    int *dp=new int[n+1];
    for (int i=0;i<=n;i++){
        dp[i]=-1;
    }
    fib_helper(n,dp);
}
int main(){
    cout << fib(6) <<endl;
    cout << fib(10) <<endl;
    return 0;
}