#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int u=0,l=0;
    for(int i=0; i<s.length(); i++){
        if((int)s[i]>=97){
            l++;
        }
        else{
            u++;
        }
    }
    if(u>l){
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    else{
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    cout<<s<<"\n";
    return 0;
}