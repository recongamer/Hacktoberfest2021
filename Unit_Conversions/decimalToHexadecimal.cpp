// Decimal to Hexa decimal : 

#include<bits/stdc++.h>
using namespace std;

void decimalToHexa(int n){
    char arr[100];// to store the hexa value
    int c = 0;//counter to traverse

    while (n>0){
        int r=0;
        r = n % 16;
        if(r<10){
            arr[c] = r + 48;
            c++;
        }else {
            arr[c] = r + 55;
            c++;
        }
        
        n /= 16;
    }

    for(int j = c-1; j>=0; j--){
        cout<<arr[j];
    }

}

int32_t main(){
    int n;
    cin >> n;

    decimalToHexa(n);
    return 0;
}