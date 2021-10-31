#include <iostream>
#include <climits>
using namespace std;
int EditDistance(string s,string t){
    int u=s.size();
    int v=t.size();
    int a=INT_MAX;
    int b=INT_MAX;
    int c=INT_MAX;
    int **dp=new int *[u+1];
    for (int i=0;i<=u;i++){
        dp[i]=new int[v+1];
    }
    for (int i=0;i<=v;i++){
        dp[0][i]=i;
    }
    for (int i=0;i<=u;i++){
        dp[i][0]=i;
    }
    for (int i=1;i<=u;i++){
        for (int j=1;j<=v;j++){
            if (s[u-i]==t[v-j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                a=dp[i-1][j-1];
                b=dp[i][j-1];
                c=dp[i-1][j];
                dp[i][j]=min(a,min(b,c))+1;
            }
        }
    }
    return dp[u][v];
}
int main(){
    string s="abc";
    string t="axcd";
    cout << EditDistance(s,t) <<endl;
    return 0;
}