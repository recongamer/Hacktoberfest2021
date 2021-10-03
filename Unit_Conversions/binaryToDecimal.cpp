// Binary to Decimal :

#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n){
    int ans = 0;
    int r = 1;
    while(n>0){
        int ld = n%10;
        ans += ld*r;
        r *= 2;
        n /= 10;
    }

    
    return ans;

}

int32_t main(){
  
    int n;
    cin>>n;

    cout<<binaryToDecimal(n);
    return 0;
}