#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,p=0,mp=0;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(b<a){
            mp=max(mp,p);
            
        }
        p=p+(b-a);
    }
    cout<<mp<<"\n";

    return 0;
}