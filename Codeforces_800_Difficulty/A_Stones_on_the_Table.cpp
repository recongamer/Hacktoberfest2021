#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, count=0;
    cin>>num;
    string s;
    cin>>s;
    if(num<2){
        cout<<"0\n";
    }
    else{
        for(int i=0; i<num-1; i++){
            if(s[i]==s[i+1]){
                count++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}