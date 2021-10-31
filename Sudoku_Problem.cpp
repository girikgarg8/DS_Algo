// First variation: check whether sudoku can be solved or not
#include <iostream>
using namespace std;
bool isRowSafe(int board[][4],int row,int num){
    for (int j=0;j<4;j++){
        if (board[row][j]==num){
            return false;
        }
    }
    return true;
}
bool isColSafe(int board[][4],int col,int num){
    for (int j=0;j<4;j++){
        if (board[j][col]==num){
            return false;
        }
    }
    return true;
}
bool isBoxSafe(int board[][4],int row,int col,int num){
    int rowStart=row-row%2;
    int colStart=col-col%2;
    for (int i=rowStart;i<rowStart+2;i++){
        for (int j=colStart;j<colStart+2;j++){
            if (board[i][j]==num){
                return false;
            }
        }
    }
    return true;
}
bool canPlaceNum(int board[][4],int row,int col,int num){
    if (!isRowSafe(board,row,num)){
        return false;
    }
    if (!isColSafe(board,col,num)){
        return false;
    }
    if (!isBoxSafe(board,row,col,num)){
        return false;
    }
    return true;
}
bool sudokuSolver(int board[][4]){
    int row=-1;
    int col=-1;
    bool isEmpty=false;
    //Firstly find if there is an empty cell (unocciped cell)
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (board[i][j]==0){
                isEmpty=true;
                row=i;
                col=j;
                break;
            }
        }
        if (isEmpty){
            break;
        }
    }
    if (isEmpty==false){
        return true;
    }
    for (int num=1;num<=4;num++){
        if (canPlaceNum(board,row,col,num)){
            board[row][col]=num;
            if (sudokuSolver(board)){
                return true;
            }
            board[row][col]=0;
        }
    }
    return false;
}
int main(){
    int board[4][4]={{1,3,0,4},{2,0,3,1},{0,1,0,2},{4,0,1,2}};
    cout << sudokuSolver(board) <<endl;
}