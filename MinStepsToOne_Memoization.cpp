#include <iostream>
using namespace std;
int MinStepsToOne(int n,int dp[]){
    if (n==1){
        return 0;
    }
    if (dp[n]!=(-1)){
        return dp[n];
    }
    int ans=n-1;
    int b=INT_MAX;
    int c=INT_MAX;
    int a=MinStepsToOne(n-1);
    if (n%2==0){
        b=MinStepsToOne(n/2);
    }
    if (n%3==0){
        c=MinStepsToOne(n/3);
    }
    ans=1+min(a,b,c);
    dp[n]=ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    int *dp=new int[n+1];
    for (int i=0;i<=n;i++){
        dp[i]=(-1);
    }
    cout << MinStepsToOne(n,dp);
}