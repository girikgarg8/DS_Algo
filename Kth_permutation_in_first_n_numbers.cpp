#include <bits/stdc++.h>
using namespace std;
string getPermutation_optimised(int n,int k){
    int fact=1;
    vector <int> numbers;
    for (int i=1;i<n;i++){
        fact=fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans="";
    k=k-1; //for 0 based indexing
    while (true){
        ans=ans+to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if (numbers.size()==0){
            break;
        }
        k=k%fact;
        fact=fact/numbers.size();
    }
    return ans;
}
int main(){
    int n=4;
    int k=17;
    string str=getPermutation_optimised(n,k);
    cout << str <<endl;
    return 0;
}