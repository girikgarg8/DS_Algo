#include <iostream>
using namespace std;
int main(){
    int arr[]={10,1,2,-13,0,7,-18,2};
    int n=sizeof(arr)/sizeof(int);
    int arr1[]={0,0,0,-20,0};
    int m=sizeof(arr1)/sizeof(int);
    int arr2[]={0,0,0,0,0};
    int z=sizeof(arr2)/sizeof(int);
    int arr3[]={-20};
    int x=sizeof(arr3)/sizeof(int);
    int max_product_till_i=arr2[0];
    int min_product_till_i=arr2[0];
    int o_max=max_product_till_i;
    int flag=0; //for seeing positive and negative elements
    int flag1=0;
    int count=0;
    for (int i=1;i<m;i++){
        if (arr2[i]==0){
            max_product_till_i=1;
            min_product_till_i=1;
            flag1=1;
            continue;
        }
        if (arr2[i]<0){
            count++;
        }
        max_product_till_i=max(arr2[i],max(arr2[i]*max_product_till_i,arr2[i]*min_product_till_i));
        min_product_till_i=min(arr2[i],min(arr2[i]*max_product_till_i,arr2[i]*min_product_till_i));
        o_max=max(o_max,max_product_till_i);
    }
    // o_max=1 is possible for arrays arr1 and arr2
    if (o_max==1){
    if (flag1==1 && count==1){
        cout << 0 <<endl;
    }
    else if  (flag1==1)
        cout <<0 <<endl;
    }
    else cout << o_max <<endl;
    return 0;
}