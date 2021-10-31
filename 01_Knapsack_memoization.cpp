#include <iostream>
using namespace std;
int KnapSack (int values[],int weights[],int i,int w,int n,int **dp){
    if (dp[i][w]!=(-1)){
        return dp[i][w];
    }
    if (i==n || w==0){
        return 0;
    }
    if (weights[i]>w){
        return KnapSack(values,weights,i+1,w,n,dp);
    }
    int a=KnapSack(values,weights,i+1,w-weights[i],n,dp)+values[i];
    int b=KnapSack(values,weights,i+1,w,n,dp);
    return dp[i][w]=max(a,b);
}
int main(){
    int n,w;
    cout << "Enter the value of n" <<endl;
    cin >> n ;
    int *weights=new int[n];
    int *values=new int[n];
    for (int i=0;i<n;i++){
        cin>>weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    cout << "Enter maximum weight" <<endl;
    cin >> w ;
    int **dp=new int *[n+1];
    for (int i=0;i<=n;i++){
        dp[i]=new int[w+1];
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=w;j++){
            dp[i][j]=(-1);
        }
    }
    cout << "Maximum value is " << KnapSack(values,weights,0,w,n,dp) <<endl;
    return 0;
}