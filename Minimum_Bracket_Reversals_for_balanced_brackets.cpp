#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s1;
    cin>>s1;
    stack <char> s;
    int answer=0;
    int n=s1.length();
    if (n&1){
        cout << "Given string can't be balanced" <<endl;
        return 0;
    }
    for (int i=0;i<n;i++){
        if (s1[i]=='{'){
            s.push(s1[i]);
        }
        if (s1[i]=='}'){
            if (s.empty()){
                s.push(s1[i]);
            }
            else if (s.top()=='{'){
                s.pop();
            }
            else if (s.top()=='}'){
                s.push(s1[i]);
            }
        }
    }
    int d=s.size();
    if (s.size()&1){
        cout << "Given string can't be balanced" <<endl;
        return 0;
    }
    else{
        //There could be two possible approaches here
        while (!s.empty()){
            char a=s.top();
            s.pop();
            char b=s.top();
            s.pop();
            if (a==b){
                answer++;
            } 
            if (a!=b){
                answer+=2;
            }
        }
    }
    cout << "Number of reversals required are " << answer <<endl;
    return 0;
}
//Another possible approach
 // int open=0;
/* while (!s.empty()){
    if (s.top()=='{'){
        open++;
    }
    s.pop();
    }
    if (open%2==1) return d/2+1;
    else return d/2;

} 
*/