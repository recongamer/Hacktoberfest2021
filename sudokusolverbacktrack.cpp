#include "bits/stdc++.h"
using namespace std;
bool canPlace(int mat[][9] ,int i ,int j, int n ,int num){
   // check for row and column
   for(int x=0;x<n;x++){
       if(mat[x][j]==num || mat[i][x]==num){
           return false;
       }
   }
   // to check in subgrid
   int sx,sy;
   int rn=sqrt(n);
   sx=(i/rn)*rn;
   sy=(j/rn)*rn;
   for(int x=0;x<rn;x++){
       for(int y=0;y<rn;y++){
           if(mat[sx+x][sy+y]==num){
               return false;
           }
       }
   }
                //cout<<"yes";
   return true;

}
bool solveSuduko(int mat[][9],int i,int j ,int n){
   // base case
   if(i==n){
       //print the matrix
       cout<<"solution exists"<<endl;
        for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
               cout<<mat[i][j]<<" ";
             }
             cout<<endl;
        }
         return true;
    }
    //case row end
    if(j==n){
       return solveSuduko(mat,i+1,0,n);
    }
    //to detect non empty cells
    if(mat[i][j]!=0){
        return solveSuduko(mat,i,j+1,n);
    }
    //RECURSIVE CASE
    //fill the current cell with possible options
    for(int num=1;num<=n;num++){
        if(canPlace(mat,i,j,n,num)){
            mat[i][j]=num;
            bool exist=solveSuduko(mat,i,j+1,n);
            if(exist){
                return true;
            }
        }
    }
    //BACKTRAKING
    mat[i][j]=0;
    return false;
}
int main(){
    int mat[9][9]={
                 {5,3,0,0,7,0,0,0,0},
                 {6,0,0,1,9,5,0,0,0},
                 {0,9,8,0,0,0,0,6,0},
                 {8,0,0,0,6,0,0,0,3},
                 {4,0,0,8,0,3,0,0,1},
                 {7,0,0,0,2,0,0,0,6},
                 {0,6,0,0,0,0,2,8,0},
                 {0,0,0,4,1,9,0,0,5},
                 {0,0,0,0,8,0,0,7,9},
                };
                solveSuduko(mat,0,0,9);
                cout<<"your solution";
                return 0;

}
