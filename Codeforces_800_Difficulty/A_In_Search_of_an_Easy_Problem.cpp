#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool b=true;
    while(n--){
        int a;
        cin>>a;
        if(a==1){
            b=false;
        }
    }
    if(b){
        cout<<"EASY\n";
    }
    else{
        cout<<"HARD\n";
    }


    return 0;
}