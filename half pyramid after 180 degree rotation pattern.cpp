#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number of level upto which u want to print"<<endl;
    cin>>n;
    //we have to use for loop so that it can iterate and print our pattern
    for(int i=1;i<=n;i++){
        //using anpther for loop inside one for loop so that it can be for our column and main loop which will print our pattern
    for(int j=1;j<=n;j++){
        if(j<=n-i){
            cout<<" ";
        }
        else{
            cout<<"*";
        }
    }
    cout<<endl;//line break for printing starts pattern in next line
    return 0;`
}