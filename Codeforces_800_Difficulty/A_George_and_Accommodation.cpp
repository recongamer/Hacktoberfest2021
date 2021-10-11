#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,count=0;
    cin>>n;
    while(n--){
        int p,q;
        cin>>p>>q;
        if(q-p>=2){
            count++;
        }
    }
    cout<<count<<"\n";

    return 0;
}