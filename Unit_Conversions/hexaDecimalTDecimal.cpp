//  Hexadecimal To Decimal :

#include<bits/stdc++.h>
using namespace std;

int hexadecimalToDecimal(string n){

    int ans = 0;
    int r = 1;
    int s = n.size();
    for(int i=s-1; i>=0; i--){

        if(n[i] >= '0' && n[i] <= '9'){
            ans += (n[i] - '0') * r;
        }
        else if(n[i] >= 'A' && n[i] <= 'F'){
            ans += (n[i] - 'A' + 10) * r;
        }

        r *= 16;
        
    }

    return ans;

}



int32_t main(){

    string n;
    cin>>n;

    cout<<hexadecimalToDecimal(n);
    return 0;
}