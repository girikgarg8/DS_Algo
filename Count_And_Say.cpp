#include <iostream>
using namespace std;
string CountAndSay(int x){
    if (x==1){
        return "1";
    }
    string s=CountAndSay(x-1);
    int counter=0;
    string res="";
    int n=s.length();
    for (int i=0;i<n;i++){
        counter++;
        if (i==n-1 || s[i]!=s[i+1]){
            res=res+to_string(counter)+s[i];
            counter=0;
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    cout << CountAndSay(n) <<endl;
    return 0;
}