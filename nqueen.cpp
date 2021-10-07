#include <iostream>
using namespace std;
bool issafe(int arr[][5],int x,int y,int n){
    for(int i=0;i<x;i++){
        if(arr[i][y]==1){
            return false;
        }
    int row=x;
    int column=y;
    while(row>=0&& column>=0){
        if(arr[row][column]==1){
            return false;
        }
        row--;
        column--;
    }
    row=x;
    column=y;
    while(row>=0 && column<n){
        if(arr[row][column]==1){
            return false;
        }
        row--;
        column++;
    }    
    
    }
    return true;
}
bool placingqueen(int arr[][5],int x,int n){
    if(x==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    cout<<'Q';
                }
                else{
                    cout<<"_ ";
                }
            }cout<<endl;
        }
        return true;
    }
    for(int column=0;column<n;column++){
        if(issafe(arr,x,column,n)){
            arr[x][column]=1;
        
        if(placingqueen(arr,x+1,n)){
            return true;
        }
        arr[x][column]=0;
        return false;
        }
} 
return false;   
}
int main(){
 int arr[5][5]={0};
 placingqueen(arr,0,5);
 return 0;
}