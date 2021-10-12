#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,prev=0,count=0;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        if(a!=prev){
            count++;
        }
        prev=a;
    }
    cout<<count<<"\n";

    return 0;
}