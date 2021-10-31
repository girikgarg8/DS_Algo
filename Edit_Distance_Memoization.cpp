#include <iostream>
using namespace std;
int EditDistance(string s,string t,int **dp){
    int u=s.size();
    int v=t.size();
    if (dp[u][v]!=(-1)){
        return dp[u][v];
    }
    if (s.size()==0){
        return t.size();
    }
    if (t.size()==0){
        return s.size();
    }
    if (s[0]==t[0]){
        return EditDistance(s.substr(1),t.substr(1),dp);
    }
    int a=1+EditDistance(s.substr(1),t.substr(1),dp); //Update the character
    int b=1+EditDistance(s,t.substr(1),dp); //Removing the character
    int c=1+EditDistance(s.substr(1),t,dp); //Adding a character
    int ans=min(a,min(b,c));
    return dp[u][v]=ans;
}
int main(){
    string s1, s2;
    cout << "Enter the two strings" << endl;
    cin >> s1 >> s2;
    int a=s1.length();
    int b=s2.length();
    int **dp=new int * [a+1];
    for (int i=0;i<=a;i++){
        dp[i]=new int[b];
    }
    for (int i=0;i<=a;i++){
        for (int j=0;j<=b;j++){
            dp[i][j]=-1;
        }
    }
    cout << EditDistance(s1, s2,dp) << endl;
    return 0;
}