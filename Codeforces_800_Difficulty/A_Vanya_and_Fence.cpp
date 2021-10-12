#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,h,w=0;
    cin>>n>>h;
    while(n--){
        int a;
        cin>>a;
        if(a>h){
            w+=2;
        }
        else{
            w++;
        }
    }
    cout<<w<<"\n";
    return 0;
}