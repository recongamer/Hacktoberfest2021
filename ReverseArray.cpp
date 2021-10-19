#include<bits/stdc++.h>
using namespace std ;

void reversearray(int n , int arr[]){
    int i = 0 ;
    int j = n - 1;
    for(i=0 ; i< j ; i++ , j--){
        int temp = arr[i];
        arr[i]= arr[j];
        arr[j] = temp ;

    }
    for(int i = 0  ; i < n ; i++){
        cout<< arr[i]<<" ";
    }

}
int main(){
    int n; 
    cin >> n ;
    int arr[n];
    for(int i = 0 ; i< n ; i++){
        cin >> arr[i]; 
    }

    reversearray( n , arr);

}
