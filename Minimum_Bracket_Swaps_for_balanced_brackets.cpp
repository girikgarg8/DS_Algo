#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int open=0;
    int close=0;
    int fault=0;
    int ans=0;
    int n=s.length();
    for (int i=0;i<n;i++){
        if (s[i]==']'){
            close++;
            fault=close-open;
        }
        else if (s[i]=='['){
            open++;
            if (fault>0){
                ans+=fault;
                fault--;
            }
        }
    }
    cout <<ans <<endl;
    return 0;
}