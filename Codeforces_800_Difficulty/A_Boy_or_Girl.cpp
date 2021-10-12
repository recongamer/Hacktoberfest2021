#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string s2="";
    for(int i=0; i<s.length(); i++){
        int flag=1;
        for(int j=i+1; j<s.length(); j++){
            if(s[i]==s[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            s2+=s[i];
        }
    }
    if(s2.length()%2!=0){
        cout<<"IGNORE HIM!\n";
    }
    else{
        cout<<"CHAT WITH HER!\n";
    }

    return 0;
}