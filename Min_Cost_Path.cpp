#include <iostream>
#include <climits>
using namespace std;
int MinCostPath(int **mat,int i,int j,int m,int n,int **dp){
    if (dp[i][j]!=(-1)){
        return dp[i][j];
    }
    if (i==m-1 && j==n-1){
        return mat[i][j];
    }
    int x=INT_MAX;
    int y=INT_MAX;
    int z=INT_MAX;
    if ((i+1)<m && (j)<n){
    x=MinCostPath(mat,i+1,j,m,n,dp);
    }
    if (i<m && (j+1)<n){
    y=MinCostPath(mat,i,j+1,m,n,dp);
    }
    if ((i+1)<m && (j+1)<n){
    z=MinCostPath(mat,i+1,j+1,m,n,dp);
    }
    int cost=min(x,min(y,z))+mat[i][j];
    return dp[i][j]=cost;
}
int main(){
    int row,column;
    cout << "Enter the number of rows" <<endl;
    cin>>row;
    cout << "Enter the number of columns" <<endl;
    cin>>column;
    int **arr=new int *[row];
    int **dp= new int *[row];
    for (int i=0;i<row;i++){
        arr[i]=new int [column];
        dp[i]=new int[column];
    }
    for (int i=0;i<row;i++){
        for (int j=0;j<column;j++){
            cout << "Enter data of row " << i << " and column " << j <<endl;
            cin>>arr[i][j];
            dp[i][j]=(-1);
        }
    }
    cout << MinCostPath(arr,0,0,row,column,dp);
    return 0;
}