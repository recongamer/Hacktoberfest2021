//  Decimal To Octal : 

#include<bits/stdc++.h>
using namespace std;

void octalToDecimal(int n){
    int arr[32];// Array to store ans
    int k = 0; // counter to traverse the answer array

    while (n>0){
        arr[k] = n % 8;
        n /= 8;
        k++; 
    }
    for(int j=k-1; j>=0; j--){
        cout<<arr[j];
    }

}

int32_t main(){
    int n;
    cin>>n;

    octalToDecimal(n);
    return 0;
}