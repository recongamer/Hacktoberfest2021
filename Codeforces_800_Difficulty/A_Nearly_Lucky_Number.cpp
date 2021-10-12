#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    int count=0;
    cin>>n;
    while(n){
        if(n%10==4 || n%10==7){
            count++;
        }
        n/=10;
    } 
    if(count==4 || count==7){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }


    return 0;
}