#include<iostream>
using namespace std;
//function to check that wether the arr[nextrow][nextcol] is available for the knight to come or not....
bool ispossible(int arr[][8],int column,int row){
    if((column>=0)&&(column<8)&&(row>=0) && (row<8) && (arr[row][column]==0)){
        return true;
    }
    return false;
}
//main function...
bool knightsmovement(int arr[][8],int row,int column,int move){
    int mover[8]={-2,-1,+1,+2,+2,+1,-1,-2};
    int movec[8]={+1,+2,+2,+1,-1,-2,-2,-1};
    //as it is 8*8 board if the move reaches '64' then it means that we are done the task and then we will print the updated board..
    if(move==64){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
               cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int i=0;i<8;i++){
        int nextrow=row+mover[i];
        int nextcolumn=column+movec[i];
        if(ispossible(arr,nextcolumn,nextrow)){
            move++;
            arr[nextrow][nextcolumn]=move;
        //again running the main function recursively with row=nextrow and column=nextcolumn and if it returns false we will backtrack ..
        if(knightsmovement(arr,nextrow,nextcolumn,move)){
            return true;
        }
        //backtracking..
        move--;
        arr[nextrow][nextcolumn]=0;

        }

    }
    return false;

}
int main(){
    int arr[8][8]={0};
    arr[0][0]=1;
    int row=0;
    int column=0;
    int move=1;
    knightsmovement(arr,row,column,move);
    return 0;
}
