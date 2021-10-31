#include <iostream>
using namespace std;
int fib_helper(int n,int dp[]){
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    if (dp[n]!=(-1)){
        return dp[n];
    }
    int a=fib(n-1);
    int b=fib(n-2);
    dp[n]=a+b;
    return a+b;
}
int fib(n){
    int *dp=new int[n+1];
    for (int i=0;i<=n;i++){
        dp[i]=(-1);
    }
    fib_helper(n,dp);
}
int main(){
    cout << fib(6) <<endl;
    cout << fib(10) <<endl;
    return 0;
}