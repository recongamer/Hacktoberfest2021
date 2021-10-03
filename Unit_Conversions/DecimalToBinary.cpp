//  Decimal To Binary : 


#include<bits/stdc++.h>
using namespace std;

void DecimalToBinary(int n){

    int arr[32];

    int k=0;

    while(n > 0){
       
        arr[k] = n % 2;
        n = n / 2;
        k++;

    }
    for(int j = k-1; j >= 0; j-- ){
        cout<<arr[j];
    }

} 

int32_t main(){
  
  int n;
  cin>>n;

  DecimalToBinary(n);

  return 0;
}