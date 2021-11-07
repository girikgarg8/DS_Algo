#include <bits/stdc++.h>
using namespace std;
int find_removals(string s){
    stack <char> st;
    for (int i=0;i<s.length();i++){
        if (s[i]=='('){
            st.push(s[i]);
        }
        else if (s[i]==')'){
            if (st.size()!=0 && st.top()=='('){
                st.pop();
            }
            else{
                st.push(')');
            }
        }
    }
    return st.size();
}
void solve(string s,vector <string> &ans,unordered_map <string,bool> &mp,int removals){ //recursive function
    if (mp[s]){ //if a particular string has already been formed, don't try to orm it again
        return ;
    }
    mp[s]=true;
    if (removals==0){
        int removals_needed=find_removals(s);
        if (removals_needed==0)
            ans.push_back(s);
            return ;
    }

    for (int i=0;i<s.length();i++){
        string leftpart=s.substr(0,i);
        string rightpart=s.substr(i+1);
        string join=leftpart+rightpart;
        solve(join,ans,mp,removals-1);
    }
}
vector <string> removeInvalidParanthesis (string s){
    unordered_map <string,bool> mp;
    int min_removal=find_removals(s); //Firstly find the number of removals required by using tsandard stack technique
    vector <string> ans;
    solve (s,ans,mp,min_removal);
    return ans; //return the vector of all valid strings 
}
int main(){
    string str="()())()";
    vector <string> v=removeInvalidParanthesis(str);
    for (auto x:v){
        cout << x <<endl;
    }
    return 0;
}
