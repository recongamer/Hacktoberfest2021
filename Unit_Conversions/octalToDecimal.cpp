//  Octal to Decimal : 

#include<bits/stdc++.h>
using namespace std;

int octalToDecimal(int n){

    int r=1;
    int ans = 0;
    while(n>0){ 
        int ld = n%10;
        ans += ld*r;
        r *= 8;
        n /= 10;
    }
    return ans;
}



int32_t main(){
  int n;
  cin>>n;

  cout<<octalToDecimal(n);
}