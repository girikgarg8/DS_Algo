#include <iostream>
using namespace std;
int LCS (string s,string t,int **dp){
    int u=s.length();
    int v=t.length();
    if (dp[u][v]!=(-1)){
        return dp[u][v];
    }
    //Base case
    if (s.length()==0 || t.length()==0){
        return 0;
    }
    //Recursive call
    if (s[0]==t[0]){
        return 1+LCS(s.substr(1),t.substr(1),dp);
    }
    else{
        int a=LCS(s.substr(1),t,dp);
        int b=LCS(s,t.substr(1),dp);
        int c=LCS(s.substr(1),t.substr(1),dp);
        return dp[u][v]=max(a,max(b,c));
    }
}
int main(){
    string s,t;
    getline(cin,s);
    getline(cin,t);
    int m=s.length();
    int n=t.length();
    int **dp= new int *[m+1];
    for (int i=0;i<=n;i++){
        dp[i]=new int[n+1];
    }
    for (int i=0;i<=m;i++){
        for (int j=0;j<=n;j++){
            dp[i][j]=(-1);
        }
    }
    cout << LCS(s,t,dp);
    return 0;
}
