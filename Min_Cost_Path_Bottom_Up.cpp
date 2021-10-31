#include <iostream>
using namespace std;
int MinCostPath(int **mat,int m,int n){
    int dp[m][n];
    dp[m-1][n-1]=mat[m-1][n-1];
    for (int i=n-2;i>=0;i--){
        dp[m-1][i]=dp[m-1][i+1]+mat[m-1][i];
    }
    for (int i=m-2;i>=0;i--){
        dp[i][n-1]=dp[i+1][n-1]+mat[i][n-1];
    }
    for (int i=m-2;i>=0;i--){
        for (int j=n-2;j>=0;j--){
            int a=dp[i+1][j];
            int b=dp[i][j+1];
            int c=dp[i+1][j+1];
            dp[i][j]=min(a,min(b,c))+mat[i][j];
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout <<dp[i][j] << " ";
        }
        cout <<endl;
    }
    return dp[0][0];
}
int main(){
    int row,column;
    cout << "Enter the number of rows" <<endl;
    cin>>row;
    cout << "Enter the number of columns" <<endl;
    cin >>column;
    int **mat=new int *[row];
    for (int i=0;i<row;i++){
        mat[i]=new int[column];
    }
    for (int i=0;i<row;i++){
        for (int j=0;j<column;j++){
            cin>>mat[i][j];
        }
    }
    cout << MinCostPath(mat,row,column) <<endl;
    delete [] mat;
    return 0;
}