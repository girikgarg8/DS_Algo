#include <iostream>
using namespace std;
void computeLPSArray(string pattern,int *LPS,int size);
void KMPsearch(string text,string pattern){
    int a=text.size();
    int b=pattern.size();
    int LPS[b];
    computeLPSArray(pattern,LPS,b);
    int i=0;
    int j=0;
    while (i<a){
        if (pattern[j]==text[i]){
            i++;
            j++;
        }
        if (j==b){ //this means we have found the given pattern in the text, hence we should print the index at which we found it
            cout << "Pattern found at index " << i-j <<endl;
            j=LPS[j-1]; //to check for multiple occurences
        }
        else if (i<a && pattern[j]!=text[i]){
            if (j!=0)
            j=LPS[j-1];
            else
            i=i+1;
        }
    }
}
void computeLPSArray(string pattern,int *LPS,int size){
LPS[0]=0;
int m=size;
int i=0;
int j=1;
while (j<m){
    if (pattern[i]==pattern[j]){
        LPS[j]=i+1; //not LPS[i]+1
        i++;
        j++;
    }
    else {
        if (i!=0){ 
            i=LPS[i-1];
        }
        else if (i==0){
            LPS[j]=0;
            j++;
            }   
        }
    }
}
int main(){
    string text="ABABDABACDABABCABAB";
    string pattern="ABABCABAB";
    KMPsearch(text,pattern);
    return 0;
}
